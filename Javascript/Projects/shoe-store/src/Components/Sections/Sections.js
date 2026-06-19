import React from 'react'
import { Route, Routes } from 'react-router-dom'
import { Products } from './Products';
import { Details } from './Details'
import { Nfound } from '../Nfound'
import { Home } from './Home';
import {Cart} from './Cart'
export const Section = () => {
    return (
        <div> 
            <section>
            <Routes>
            <Route path="/" element={<Home />}></Route>

                <Route path="/home" element={<Home />}></Route>
                <Route path="product" element={<Products />}></Route>
                    <Route path="/product/:proId" element={<Details />} />
                <Route path="*" element={<Nfound/>}></Route>
                <Route path="/cart" element={<Cart/>}></Route>
            </Routes>
            
            </section>
        </div>
    )
}