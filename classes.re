type state = {
  .
  "id": float,
  "storeName": string,
};
module Store = {
  type t = {
    .
    "state": state,
    "update": [@bs.meth] (state => unit),
  };
  [@bs.new] [@bs.module "classes"] external make: state => t = "Store";
};
