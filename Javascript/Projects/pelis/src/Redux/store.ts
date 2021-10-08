import { createStore, combineReducers, applyMiddleware } from "redux";
import thunk from "redux-thunk";
import { composeWithDevTools } from "redux-devtools-extension";

import pelisReducer from "./pelisDuck";

const rootReducer = combineReducers({
  peliculas: pelisReducer,
});

export default function generateStore() {
  const store = createStore(
    rootReducer,
    composeWithDevTools(applyMiddleware(thunk))
  );
  return store;
}
