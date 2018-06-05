/* file: BasicMap.re */

type state = {locations: array(Fetcher.data)};

type action =
  | SetData(array(Fetcher.data));

let component = ReasonReact.reducerComponent("BasicMap");

let make = _children => {
  ...component,
  initialState: () => {locations: [||]},
  reducer: (action, state) =>
    switch (action) {
    | SetData(locations) => ReasonReact.Update({locations: locations})
    },
  didMount: self => {
    Fetcher.fetchPost(
      ~url="https://immense-river-25513.herokuapp.com/add-location",
      ~body="ernestobarros",
    );
    Fetcher.fetchGet(
      ~url="https://immense-river-25513.herokuapp.com/locations",
      ~cb=(locations: array(Fetcher.data)) =>
      self.send(SetData(locations) /* Js.log(locations); */)
    );
  },
  render: self => {
    let locations = self.state.locations;
    <ComposableMap>
      <ZoomableGroup>
        <Geographies geography="world-50m.json">
          (
            (geographies, projection) =>
              Array.mapi(
                (idx, geography) =>
                  <Geography key=(string_of_int(idx)) geography projection />,
                geographies,
              )
          )
        </Geographies>
        <Markers>
          (
            Array.mapi(
              (idx, data: Fetcher.data) => {
                let location = Fetcher.location(data);
                <Marker
                  key=(string_of_int(idx)) marker={coordinates: location}>
                  <circle cx="0" cy="0" r="2" fill="red" />
                </Marker>;
              },
              locations,
            )
          )
        </Markers>
      </ZoomableGroup>
    </ComposableMap>;
  },
};