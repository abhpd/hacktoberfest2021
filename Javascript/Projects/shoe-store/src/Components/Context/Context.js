import React, { createContext, useReducer } from 'react'

import AppReducer from './AppReducer';
// const { proId } = useParams();

const initialState = {
    products: [
        {
            "_id": "1",
            "title": "Nike Shoes 01",
            "src": "https://www.upsieutoc.com/images/2020/06/27/img1.jpg",
            "description": "UI/UX designing, html css tutorials",
            "content": "Welcome to our channel Dev AT. Here you can learn web designing, UI/UX designing, html css tutorials, css animations and css effects, javascript and jquery tutorials and related so on.",
            "price": 23,
            "colors": ["red", "black", "crimson", "teal"],
            "count": 1
        },
        {
            "_id": "2",
            "title": "Nike Shoes 02",
            "src": "https://www.upsieutoc.com/images/2020/06/27/img2.jpg",
            "description": "UI/UX designing, html css tutorials",
            "content": "Welcome to our channel Dev AT. Here you can learn web designing, UI/UX designing, html css tutorials, css animations and css effects, javascript and jquery tutorials and related so on.",
            "price": 19,
            "colors": ["red", "crimson", "teal"],
            "count": 1
        },
        {
            "_id": "3",
            "title": "Nike Shoes 03",
            "src": "https://www.upsieutoc.com/images/2020/06/27/img3.jpg",
            "description": "UI/UX designing, html css tutorials",
            "content": "Welcome to our channel Dev AT. Here you can learn web designing, UI/UX designing, html css tutorials, css animations and css effects, javascript and jquery tutorials and related so on.",
            "price": 50,
            "colors": ["lightblue", "white", "crimson", "teal"],
            "count": 1
        },
        {
            "_id": "4",
            "title": "Nike Shoes 04",
            "src": "https://www.upsieutoc.com/images/2020/06/27/img4.jpg",
            "description": "UI/UX designing, html css tutorials",
            "content": "Welcome to our channel Dev AT. Here you can learn web designing, UI/UX designing, html css tutorials, css animations and css effects, javascript and jquery tutorials and related so on.",
            "price": 15,
            "colors": ["orange", "black", "crimson", "teal"],
            "count": 1
        },
        {
            "_id": "5",
            "title": "Nike Shoes 05",
            "src": "https://www.upsieutoc.com/images/2020/06/27/img5.jpg",
            "description": "UI/UX designing, html css tutorials",
            "content": "Welcome to our channel Dev AT. Here you can learn web designing, UI/UX designing, html css tutorials, css animations and css effects, javascript and jquery tutorials and related so on.",
            "price": 10,
            "colors": ["orange", "black", "crimson", "teal"],
            "count": 1
        },
        {
            "_id": "6",
            "title": "Nike Shoes 06",
            "src": "https://www.upsieutoc.com/images/2020/06/27/img6.jpg",
            "description": "UI/UX designing, html css tutorials",
            "content": "Welcome to our channel Dev AT. Here you can learn web designing, UI/UX designing, html css tutorials, css animations and css effects, javascript and jquery tutorials and related so on.",
            "price": 17,
            "colors": ["orange", "black", "crimson", "teal"],
            "count": 1
        },
        {
            "_id": "7",
            "title": "Nike Shoes 07",
            "src": "https://www.upsieutoc.com/images/2020/06/27/img6.jpg",
            "description": "UI/UX designing, html css tutorials",
            "content": "Welcome to our channel Dev AT. Here you can learn web designing, UI/UX designing, html css tutorials, css animations and css effects, javascript and jquery tutorials and related so on.",
            "price": 19,
            "colors": ["orange", "black", "crimson", "teal"],
            "count": 1
        },
        {
            "_id": "8",
            "title": "Nike Shoes 08",
            "src": "https://www.upsieutoc.com/images/2020/06/27/img6.jpg",
            "description": "UI/UX designing, html css tutorials",
            "content": "Welcome to our channel Dev AT. Here you can learn web designing, UI/UX designing, html css tutorials, css animations and css effects, javascript and jquery tutorials and related so on.",
            "price": 39,
            "colors": ["orange", "black", "crimson", "teal"],
            "count": 1
        }
    ],
    cart: [

    ]
}
export const GlobalState = createContext(initialState);
export const GlobalProvider = ({ children }) => {
    // const [Cart, setCart] = useState(initialState)
    const [state,dispatch] = useReducer(AppReducer,initialState)
    const functionaddCart=({_id})=> {
        // const data = initialState.products.filter(p => p._id===_id); 
        dispatch({
            type:"addCart",
            payload:_id
        })
    }
    const DeleteProduct =({_id})=>{
        dispatch({
                type:"deletProd",
                payload:_id
            }
        )
    }
    
    return (
        <GlobalState.Provider value={{
            initialState:state,functionaddCart,DeleteProduct
        }
        }>
            {children}
        </GlobalState.Provider>
    )
}    
