import React from 'react'
import { Link } from 'react-router-dom'

export default function Nav(props) {
    
    

    return (
        
        <>
        <nav className={`navbar navbar-expand-lg navbar-${props.darkMode} bg-${props.darkMode}`}>
            <Link className="navbar-brand" to="/">TextUtils</Link>
            <button className="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                <span className="navbar-toggler-icon"></span>
            </button>

            <div className="collapse navbar-collapse" id="navbarSupportedContent">
                <ul className="navbar-nav mr-auto">
                <li className="nav-item active">
                    <Link className="nav-link" to="/">Home <span className="sr-only">(current)</span></Link>
                </li>
                <li className="nav-item">
                    <Link className="nav-link" to="/about">About</Link>
                </li>
                
                
                </ul>
                <div className={`custom-control custom-switch text-${props.darkMode}`}>
                    <input type="checkbox" className="custom-control-input" onClick={props.toggleMode} id="customSwitch1" />
                    <label className="custom-control-label" htmlFor="customSwitch1"  style={{color:props.darkMode==='light'?'black':'white'}}>Dark Mode</label>
                </div>
            </div>
        </nav>
        </>
    )
}
