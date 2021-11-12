import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import App from './App';
import reportWebVitals from './reportWebVitals';
import { createStore,combineReducers} from 'redux';
import { Provider } from 'react-redux';
import allReducer from './reducers';  //no need to go to the reducers/index.js. the webpack auto picks up the file.

const store=createStore(
  allReducer,
  window.__REDUX_DEVTOOLS_EXTENSION__ && window.__REDUX_DEVTOOLS_EXTENSION__()       //this will allow you to visualize the data through the redux browser extension
  );

ReactDOM.render(
    <Provider store={store}>    
    <App />,
    </Provider>,                                             //this allows the application to use the redux store throughout the entire application.
  document.getElementById('root')
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
