/* file: ZoomableGroup.re */

[@bs.module "react-simple-maps"]
external zoomableGroupClass: ReasonReact.reactClass = "ZoomableGroup";

let make = (children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=zoomableGroupClass,
    ~props=Js.Obj.empty,
    children,
  );