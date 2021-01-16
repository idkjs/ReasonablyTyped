open Belt;

exception UnrecognizedInput(string);

module Args = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    input: string,
    [@bs.optional]
    output: string,
    [@bs.optional]
    debug: bool,
    args: array(string),
  };
  external decode : Js.Json.t => t = "%identity";
};

let inferInputTypeFromFileExtension = filename =>
  switch (filename) {
  | _ when Js.String.endsWith(".d.ts", filename) => Compiler2.TypeScriptDefintion
  | _ when Js.String.endsWith(".js", filename) => Compiler2.FlowDefinition
  | _ when Js.String.endsWith(".css", filename) => Compiler2.CSS
  | _ when Js.String.endsWith(".gql", filename) => Compiler2.GraphQL
  | _ when Js.String.endsWith(".graphql", filename) => Compiler2.GraphQL
  | _ when Js.String.endsWith(".typed.js", filename) => Compiler2.Typed
  | _ when Js.String.endsWith(".typed", filename) => Compiler2.Typed
  | _ => raise(UnrecognizedInput(filename))
  };

let guessOutuptFilename = output =>
  Compiler2.(
    switch (output) {
    | {type_: Reason, name} when Js.String.endsWith(".d.ts", name) =>
      Js.String.replace(".d.ts", ".re", name)
    | {type_: Reason, name} when Js.String.endsWith(".js", name) =>
      Js.String.replace(".js", ".re", name)
    | {type_: Reason, name} => name ++ ".re"

    | {type_: FlowDefinition, name} when Js.String.endsWith(".d.ts", name) =>
      Js.String.replace(".d.ts", ".js", name)
    | {type_: FlowDefinition, name} when Js.String.endsWith(".js", name) => name
    | {type_: FlowDefinition, name} => name ++ ".js"

    | {name} => name
    }
  );

let optionToFileType = input =>
  switch (input) {
  | "dts" => Compiler2.TypeScriptDefintion
  | "flow" => Compiler2.FlowDefinition
  | "css" => Compiler2.CSS
  | "graphql" => Compiler2.GraphQL
  | "typed" => Compiler2.Typed
  | "reason" => Compiler2.Reason
  | _ => raise(UnrecognizedInput(input))
  };

let program =
  Commander.program
  |. Commander.version("2.0.0")
  |. Commander.usage("[options] <file ...>")
  |. Commander.option("--input [type]", "Input file type")
  |. Commander.option("--output [type]", "Output file type")
  |. Commander.option("--debug", "Run in debug mode")
  |. Commander.parse(Commander.Process.argv)
  |. Args.decode;

let filename = program |. Args.argsGet |. Array.get(0) |. Option.getExn;

let inputType =
  program
  |. Args.inputGet
  |. Option.mapWithDefault(
       inferInputTypeFromFileExtension(filename),
       optionToFileType,
     );

let outputType =
  program
  |. Args.outputGet
  |. Option.map(optionToFileType)
  |. Option.getWithDefault(Compiler2.Typed);

let debug = program |. Args.debugGet |. Option.getWithDefault(false);

let inputSource = Node.Fs.readFileAsUtf8Sync(filename);

let inputFile =
  Compiler2.{type_: inputType, name: filename, source: inputSource};

let outputs = Compiler2.compile(inputFile, outputType);

Array.forEach(outputs, output =>
  if (debug) {
    Js.log(output.source);
  } else {
    let outputFilename = guessOutuptFilename(output);
    Node.Fs.writeFileAsUtf8Sync(outputFilename, output.source);
  }
);
