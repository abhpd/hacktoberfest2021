import React, { useContext, useEffect, useState } from "react";
// import { Profiler } from 'react';
import { useParams, Link } from "react-router-dom";
import "./details.css";
import { GlobalState } from "../Context/Context";
export const Details = () => {
  const x = useContext(GlobalState);
  const prd = x.initialState.products;
  console.log(prd);
  const { proId } = useParams();
  useEffect(() => {
    getFilterShoes();
  });
  const getFilterShoes = () => {
    if (proId) {
      const res = prd;
      const data = res.filter((item) => {
        return item._id === proId;
      });
      setProducts(data[0]);
    }
  };
  const [ProFilter, setProducts] = useState({ colors: [] });
  console.log(ProFilter);
    const {functionaddCart}  = x;
  //  console.log(typeof(functionaddCart.cart))
  return (
    <div className="cardDetails">
      <img alt={ProFilter.title} src={ProFilter.src} />
      <div className="box">
        <div className="row">
          <h2>{ProFilter.title}</h2>
          <span>${ProFilter.price}</span>
        </div>

        {/* {ProFilter.colors ? ProFilter.colors.map((color, index)=> (
                    <button key={index}>{color}</button>
                    )): ""}
                */}
        <p className="color">
          {ProFilter.colors.map((color, index) => (
            <button key={index} style={{ background: color }}>
              0
            </button>
          ))}
        </p>
        <p className="description">{ProFilter.description}</p>
        {/* {console.log(ProFilter)} */}
        <p>{ProFilter.content}</p>
        <Link to="/cart" className="cartd">
          <button onClick={() => functionaddCart(ProFilter)}
            type="button">
            Add to cart
          </button>
          {/* when i am addition this onclick following error occur in cart cart k sath koi connection nahi ha phr q aa raha ha  WHY?
                 TypeError: Cannot read property '_id' of undefined
  12 | <hr />
  13 | 
  14 | {crt.map((cart=>
> 15 |     <div className="card" key={cart._id}> 
     | ^  16 |         <img src={cart.src}/>
  17 |         <h1>{cart.title}</h1>
  18 |         <span>${cart.price}</span>
                */}
        </Link>
      </div>
    </div>
  );
};
