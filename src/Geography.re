/* file: Geography.re */

[@bs.module "react-simple-maps"]
external geographyClass : ReasonReact.reactClass = "Geography";

let make = (~geography, ~projection, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=geographyClass,
    ~props={"geography": geography, "projection": projection},
    children,
  );