// open Belt;

// let compile = (fileName, fileSource, runtimeStr, typesStr) => {
//   let debug = false;
//   let optimize = false;
//   let runtime ={
//   let types = Compiler.types(typesStr);}
exception ReportableError(string);

let compile = (moduleName, moduleSource, debug) => {
  open Compiler;
  let result =
    try(
      Stage.parseSource(moduleName, moduleSource)
      |> Imports.link
      |> List.map(Stage.optimizeAst)
      |> Stage.renderAst
      |> Stage.combineAst
      |> (((id, code)) => (id, code, [||]))
    ) {
    | Parse_error.Error(xs) => (
        "Unknown ID",
        "",
        Diagnostic.diagnosticOfFlow(xs, moduleSource),
      )
    | Diagnostic.Error(xs) => ("Unknown ID", "", xs)
    };
  if (debug) {
    let debugAsts = Stage.parseSource(moduleName, moduleSource);
    Stage.Debug.showSource(moduleName, moduleSource);
    Stage.Debug.showImports(debugAsts);
    Stage.Debug.showTypes(debugAsts);
    Stage.Debug.showFlow(debugAsts);
    Stage.Debug.showCode(result);
  };
  result;
};
include Belt.Result;
let catchExn: ('a, 'a => 'b) => t('b, exn) =
  (x, f) =>
    try(Ok(x->f)) {
    | e => Error(e)
    };
exception FmtedCodeErr(string);

let badFunction = source =>
  Reason.printRE(Reason.parseRE(source)) == string_of_int(3)
    ? raise(FmtedCodeErr(source)) : source;

// let errorLocation = (loc: Loc.t) =>
//   Errors2.{
//     source: "",
//     column: loc.start.column,
//     line: loc.start.line,
//     length: 0,
//   };
// let badFunction = n => n == 3 ? raise(FmtedCodeErr(n)) : n + 1
// let fmtedCodeErr =(e)=>{
// let location = errorLocation(e);
//     let result =  "line " ++
//       location.line->string_of_int ++
//       ", characters " ++
//       e.location.startLineStartChar ++
//       "-" ++
//       e.location.endLineEndChar ++
//       ", " ++
//       e.message ++
//       "\n" ++
//       source}
// let format(source) {
//   let fmtedCode = "NotInitialized";
//   try(try (Reason.printRE(Reason.parseRE(source))){
//       | fmtedCode =>fmtedCode
//       | exn=> "NotInitialized"

//   } catch (e) {
//     fmtedCode =
//       'line ' +
//       e.location.startLine +
//       ', characters ' +
//       e.location.startLineStartChar +
//       '-' +
//       e.location.endLineEndChar +
//       ', ' +
//       e.message +
//       '\n' +
//       source
//   }

//   return fmtedCode
// }
// let format =(source)=> {
//   let fmtedCode = "NotInitialized";
//       let kind = source |> Reason.printRE|> Reason.parseRE;
//     let decoder =
//       try (List.assoc(kind, decoders)) {
//       | _ => unknown
//       };
//     decoder(source);
//      try (Reason.printRE(Reason.parseRE(source))) {
//       | _ => unknown
//       };
//         try (List.assoc(kind, decoders)) {
//       | _ => unknown
//       };
//   try {
//     fmtedCode = reason.printRE(reason.parseRE(source))
//   } catch (e) {
//     fmtedCode =
//       "line " +
//       e.location.startLine +
//       ", characters " +
//       e.location.startLineStartChar +
//       "-" +
//       e.location.endLineEndChar +
//       ", " +
//       e.message +
//       "\n" +
//       source
//   }

//   return fmtedCode
// }

/**
 * Compiles a Flow libdef to a Reason interface, formatted and error handled
 *
 * @param {string} source Flow libdef to compile
 * @param {string} [filename] Name of file being compiled for better error messages
 * @return {string} Reason interface
 */;
// function compile(
//   source,
//   filename = "",
//   includeModule = false,
//   debugMode = false,
// ) {
//   let res
//   let resName
//   let errors

//   try {
//     const [moduleName, bsCode, diagnosticErrors] = Retyped.compile(filename, source, debugMode)
//     const fmtCode = format(bsCode)
//     res = fmtCode
//     resName = moduleName
//     errors = diagnosticErrors
//   } catch (e) {
//     console.error(e)
//     throw new Error(`${e[0][0]}`)
//   }

//   if (res.includes("SYNTAX ERROR>")) {
//     throw new Error(res)
//   }

//   if (!includeModule) {
//     return res
//   } else {
//     return {
//       moduleName: resName,
//       bsCode: res,
//       diagnosticErrors: errors
//     }
//   }
// }
