[@bs.module "promise"] external pOfString : unit => Js_promise.t(string) = "pOfString";

[@bs.module "promise"] external pOfNumber : unit => Js_promise.t(float) = "pOfNumber";

[@bs.module "promise"] external pOfArray : unit => Js_promise.t(array(string)) = "pOfArray";

[@bs.module "promise"] external pOfVoid : unit => Js_promise.t(unit) = "pOfVoid";

[@bs.module "promise"] external argPromise : (~p: Js_promise.t(string)) => unit = "argPromise";

[@bs.module "promise"] external listOfPromises : unit => array(Js_promise.t(string)) = "listOfPromises";

[@bs.module "promise"] external somePromise : Js_promise.t(array(float)) = "somePromise";
