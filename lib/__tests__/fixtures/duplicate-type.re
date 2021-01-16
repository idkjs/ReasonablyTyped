[@bs.module "duplicate-type"]
external add : (~x: [@bs.unwrap] [ | `Number(float) | `String(string)]) => float =
  "add";

[@bs.module "duplicate-type"]
external sub : (~x: [@bs.unwrap] [ | `Number(float) | `String(string)]) => float =
  "sub";
