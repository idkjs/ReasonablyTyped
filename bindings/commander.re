module Process = {
  type argv;
  [@bs.scope "process"] [@bs.val] external argv : argv = "argv";
};

type program;

[@bs.module] external program : program = "commander";

[@bs.send] external version : (program, string) => program = "version";

[@bs.send] external option : (program, string, string) => program = "option";

[@bs.send] external usage : (program, string) => program = "usage";

[@bs.send] external parse : (program, Process.argv) => Js.Json.t = "parse";
