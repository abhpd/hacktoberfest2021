import React from 'react';
import { useSelector } from 'react-redux';


const Temperature=(props)=>{
    const temp=props.temp;
    const buttonState= useSelector(state=>state.tempSwitch); //get the currnet state of the switch;
    var unit="";
    if(buttonState===false){
        unit="C";
        return (
            <div>
                {Math.round(temp-273.15)}&deg;{unit}
            </div>
        )
    }else{
        unit="F"
        return(
            <div>
                {Math.round((temp-273.15) * 9/5 + 32)}&deg;{unit}
            </div>
        )
    }
}

export default Temperature;