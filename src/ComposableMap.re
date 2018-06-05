/* file: ComposableMap.re */

[@bs.module "react-simple-maps"]
external composableMapClass: ReasonReact.reactClass = "ComposableMap";

let make = (children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=composableMapClass,
    ~props=Js.Obj.empty,
    children,
  );