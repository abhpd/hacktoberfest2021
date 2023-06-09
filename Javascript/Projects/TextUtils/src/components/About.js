import React, {useState} from 'react'

export default function About(props) {
    const [myStyle, setMyStyle] = useState({
        color: 'black',
        backgroundColor: 'white'
    })
    const [btnText, setbtnText] = useState("Enable Dark mode")
    const toggleStyle = ()=>{
        if(myStyle.color==='black'){
            setMyStyle({
                color: 'white',
        backgroundColor: 'black'
                
            })
            setbtnText('Enable Light mode');
        
        }
        else if(myStyle.color==='white'){
            setMyStyle({color: 'black',
            backgroundColor: 'white'})
            setbtnText('Enable Dark mode');
        }
    }
    
    return (
        <div>
            <div className="jumbotron"  style={{backgroundColor:props.darkMode==='light'?'white':'gray'}}>
                <h1 className="display-4"  style={{color:props.darkMode==='light'?'black':'white'}}>Hello, world!</h1>
                <p className="lead" style={{color:props.darkMode==='light'?'black':'white'}}>This is a simple hero unit, a simple jumbotron-style component for calling extra attention to featured content or information.</p>
                <hr className="my-4" />
                <p style={{color:props.darkMode==='light'?'black':'white'}}>It uses utility classes for typography and spacing to space content out within the larger container.</p>
                <button className="btn btn-secondary" onClick={props.toggleMode} style={{color:props.darkMode==='light'?'black':'white'}}>{btnText}</button>
            </div>
            
            
        </div>
    )
}
