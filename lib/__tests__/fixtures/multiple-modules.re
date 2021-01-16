[@bs.module "multiple-modules"] external someTopLevel : unit => unit = "someTopLevel";

module First = {
  [@bs.module "multiple-modules/first"] external first : unit => float = "first";
  [@bs.module "multiple-modules/first"] external second : unit => unit = "second";
};

module Second = {
  [@bs.module "multiple-modules/second"] external second : unit => string = "second";
  [@bs.module "multiple-modules/second"] external third : unit => unit = "third";
};

module Third = {
  [@bs.module "multiple-modules/third"] external third : unit => string = "third";
  [@bs.module "multiple-modules/third"] external fourth : unit => unit = "fourth";
};

module ThirdInner = {
  [@bs.module "multiple-modules/third/inner"] external third : unit => string = "third";
  [@bs.module "multiple-modules/third/inner"] external fourth : unit => unit = "fourth";
};
