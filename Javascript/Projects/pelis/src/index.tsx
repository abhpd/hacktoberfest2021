import React from "react";
import ReactDOM from "react-dom";
import { Provider } from "react-redux";
import { ThemeManager } from "./ThemeManager";
import { GlobalStyle } from "./global";
import reportWebVitals from "./reportWebVitals";
import generateStore from "./Redux/store";
import App from "./App";
import "./index.css";

const store = generateStore();
ReactDOM.render(
  <React.StrictMode>
    <Provider store={store}>
      <ThemeManager>
        <App />
        <GlobalStyle />
      </ThemeManager>
    </Provider>
  </React.StrictMode>,
  document.getElementById("root")
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
