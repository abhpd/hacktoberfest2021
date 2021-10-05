import React ,{useState} from 'react'
import About from './components/About';
import Form from './components/Form';
import Sidebar from './components/Sidebar';
import Nav from './components/Nav'

import {
  BrowserRouter as Router,
  Switch,
  Route,
  Link
} from "react-router-dom";


export default function App() {
    const [darkMode, setdarkMode] = useState('light')
    const toggleMode = ()=>{
        if(darkMode==='light')
        {
            setdarkMode('dark')
            document.body.style.backgroundColor='gray';
        }
        else
        {
            setdarkMode('light')
            document.body.style.backgroundColor='white';
        }
    }
    return (
        <>
        <Router>
        <Nav darkMode= {darkMode} toggleMode={toggleMode} />
        <Sidebar />
        <Router></Router>
        <Switch>
          <Route path="/about">
          <About darkMode={darkMode} toggleMode={toggleMode}/>
          </Route>
          <Route path="/">
          <Form darkMode= {darkMode}  />
          </Route>
        </Switch>
        </Router>
        </>
    )
}
