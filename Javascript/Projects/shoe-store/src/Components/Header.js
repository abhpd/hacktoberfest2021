import React, { useState, useContext } from 'react'
import Menu from './svg/bars-solid.svg';
import Close from './svg/times-solid.svg';
import Cart from './svg/shopping-cart-solid.svg';
import "./Header.css"
import {Link } from 'react-router-dom'
import { GlobalState } from './Context/Context';
export const Header = () => {
  const [toggle, setToggle] = useState(false);
  const x = useContext(GlobalState);
  return (
    <header>
      <div className="menu" >
        <img src={Menu} alt="menu" width="20" onClick={() => setToggle(!toggle)} />
      </div>
      <div className="logo">
        <h1><Link to="/">Nike</Link></h1>
      </div>
      <nav>
        <ul className={toggle ? "toggle" : ""}>
          <li><Link to="/home">Home</Link></li>
          <li><Link to="/product">Product</Link></li>
          <li><Link to="/Contact">Contact</Link></li>
          <li><Link to="/About">About</Link></li>
          <li><Link to="/">Login/Register</Link></li>
          <li className="close" onClick={() => setToggle(!toggle)}>
            <img src={Close} alt="close" width="20" />
          </li>
        </ul>
        <div className="nav-cart">
          <span>{x.initialState.cart.length}</span>
          <Link to="/cart">
            <img src={Cart} alt="cart" width="20" />
          </Link>
        </div>
      </nav>
    </header>
  )
}
