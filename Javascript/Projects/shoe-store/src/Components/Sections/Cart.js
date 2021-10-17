
import React,{useContext} from 'react'
import {GlobalState} from '../Context/Context' ;

export const Cart = () => {
    const x = useContext(GlobalState);
        let crt =x.initialState.cart;
        let {DeleteProduct}= x;
        console.log({DeleteProduct})
    return (
        <div>          
            
            <h1>Your Cart Details:</h1>
            <hr />
                
            {crt.map(((cart,index)=>
                <div className="card" key={index}> 
                    <img alt={cart.alt}src={cart.src}/>
                    <h1>{cart.title}</h1>
                    <span>${cart.price}</span>
                    <p>{cart.description}</p>
                    <button onClick={()=>{DeleteProduct(cart)}}>Delete</button>
                    {/* {console.log(DeleteProduct._id)} */}
                </div>  
                ))}
       </div>
    )
}
