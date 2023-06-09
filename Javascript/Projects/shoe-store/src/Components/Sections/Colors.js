import React, { useContext,useState } from 'react'
import { GlobalState } from '../Context/Context';

export const Colors = () => {
    const { products } = useContext(GlobalState);
        console.log(products)
        const [ProFilter,setProFilter ] = useState([])
        // setProFilter()
    return (
        <div>
            {
                  <h1>gdf</h1>
                   }
                    {/* // .map((color, index)=> (
                    // <button key={index} style={{background:color}}>{color}</button>
                    // ))}  */}
        </div>
    )
}
