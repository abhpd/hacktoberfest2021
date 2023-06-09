import React, { useContext } from 'react'
import {GlobalState} from '.././Context/Context';
import './products.css';
import {Link, Outlet} from 'react-router-dom'
export const Products = () => {
    // const  =useContext(GlobalState);
   
    const x = useContext(GlobalState);
    // console.log();
    let prd =x.initialState.products;
    // let  y= useContext(GlobalState);
    // console.log(x.addCart)
    // let functionaddCart =x.functionaddCart;
    // functionaddCart( idd ){
    //     console.log(idd)
    // }
    // console.log(functionaddCart)
    const {functionaddCart} = x;
        return (

       <div id="product"> 
                {
                    prd.map(product => (
                        <div className="card" key={product._id}>
                          
                            <Link to={`/product/${product._id}`} >
                                <img src={product.src} alt="" />
                            </Link>
                            <div className="content">
                                <h3>
                                    <Link to={`/product/${product._id}`}>{product.title}</Link>
                                </h3>
                                <span>${product.price}</span>
                                <p>{product.description}</p>
                               <Link to="/cart" className="buttonp" >
                                <button onClick={()=>functionaddCart(product)}>Add to cart</button>
                                </Link>
                            </div>
                        </div>
                    ))
                }
                    <Outlet/>
            </div>

        )
}