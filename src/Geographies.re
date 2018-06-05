/* file: Geographies.re */

[@bs.deriving abstract]
type jsProps = {
  geography: string,
};

[@bs.module "react-simple-maps"]
external geographiesClass: ReasonReact.reactClass = "Geographies";

let make = (~geography, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=geographiesClass,
    ~props=jsProps(~geography),
    children,
  );