/* file: Marker.re */

[@bs.module "react-simple-maps"]
external markerClass : ReasonReact.reactClass = "Marker";

let make = (~marker: Types.marker, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=markerClass,
    ~props={
      "marker": {
        "coordinates": [|snd(marker.coordinates), fst(marker.coordinates)|],
      },
    },
    children,
  );