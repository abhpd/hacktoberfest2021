import React from 'react';
import './index.css';
// import { BrowserRouter, Outlet, Route, Router, Routes, Link } from 'react-router-dom';
import { Header } from './Components/Header';
import { Section } from './Components/Sections/Sections'
import {GlobalProvider} from './Components/Context/Context';
// import {CartContext} from './Components/Context/CartContext';
function App() {
  return (
    <GlobalProvider>
      
    <div className="App">
        <Header />
        <hr/>
        <Section />
    </div>  
    
     </GlobalProvider>  
  );
}
export default App;