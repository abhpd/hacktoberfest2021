import React, {useState} from 'react'

export default function Form(props) {
    const [text, settext] = useState('Your text here')
    const clicked = ()=>{
        let text1 = text.toUpperCase();
        settext(text1);
        
    }
    const clickedLower = ()=>{
        let text1 = text.toLowerCase();
        settext(text1);
        
    }
    const changed = (event)=>{
        settext(event.target.value);
        
    }
    return (
        <div className="container"  >
            <div>
            <h1 className="my-2"  style={{color:props.darkMode==='light'?'black':'white'}}>Enter Your Text here to Analyze</h1>
            <textarea name="text" className='form-control my-3'value={text} id="text"  onChange={changed} cols="30" rows="10" style={{backgroundColor:props.darkMode==='light'?'white':'gray'}}></textarea>
            <button className={props.darkMode==='light'?'btn btn-primary mx-1':'btn btn-secondary mx-1'}onClick= {clicked} style={{color:props.darkMode==='light'?'black':'white'}}>Capitalise</button>
            <button className={props.darkMode==='light'?'btn btn-primary mx-1':'btn btn-secondary mx-1'}onClick= {clickedLower} style={{color:props.darkMode==='light'?'black':'white'}}>In to lower case</button>
            <hr />
            <h2 className="my-2" style={{color:props.darkMode==='light'?'black':'white'}} >Text-Summary</h2>
            <hr />

            <p style={{color:props.darkMode==='light'?'black':'white'}}>Your text has {text.split(" ").length} words. Your text has {text.length} letters.</p>
        </div>
        </div>
    )
}
