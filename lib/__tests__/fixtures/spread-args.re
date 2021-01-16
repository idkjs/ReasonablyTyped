[@bs.module "spread-args"] [@bs.splice] external foo : (~bars: array(float)) => unit = "foo";

[@bs.module "spread-args"] [@bs.splice] external optFoo : (~bars: array(float)) => unit = "optFoo";

[@bs.module "spread-args"] [@bs.splice]
external bothFoo : (~anArg: string, ~bars: array(float)) => unit =
  "bothFoo";

[@bs.module "spread-args"] [@bs.splice]
external bothOptFoo : (~anArg: string, ~bars: array(float)) => unit =
  "bothOptFoo";

[@bs.module "spread-args"] [@bs.splice]
external soManyOpts : (~anArg: string=?, unit, ~bars: array(float)) => unit =
  "soManyOpts";

[@bs.module "spread-args"] [@bs.splice]
external returns : (~anArg: string, ~bars: array(float)) => float =
  "returns";

[@bs.module "spread-args"] [@bs.splice]
external multipleLists : (~foos: array(float), ~bars: array(float)) => unit =
  "multipleLists";
