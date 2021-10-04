import { TextField } from '@material-ui/core';
import React from 'react';
import  { useState,useEffect } from 'react';
import ReactDOM from 'react-dom';
import Mapper from "./mapper"

const Content=(props)=>{

  const [cities, setItems] = useState([]);
  const [mapped,setMapped]=useState([]);

  // const API=api;
  const appi=props.api;
  console.log(props.api);
  console.log(cities)
  console.log(mapped);

  useEffect(() => {
    if (appi) {
      (async () => {
        try {
          const response = await fetch(appi);
          var result=[];
          result = await response.json();
          cities.shift();                               //clearing the cities array before insert new items
          const updatedCities =cities.concat(result);
          setItems(updatedCities);
        } catch(err) {
          console.error(err);
        }
      })();
    }
  }, [appi]); 
  
  useEffect(()=>{

        const currentCityMapped=cities.map(weatherDataMapper);
        setMapped(currentCityMapped);

  },[cities])


  // if(cities.length<1 ){
  //   return(
  //     <TextField>
  //       Yo fill up the array bruv
  //     </TextField>
  //   )
  // }
  // else{
    return(
      mapped.map((weather)=>
        <Mapper
          city={weather.city}
          country={weather.country}
          temperature={weather.temperature}
          description={weather.description}
          humidity={weather.humidity}
          icon={weather.icon}
          wind_speed={weather.windSpeed}
          feelsLike={weather.feelsLike}
          code={weather.code}
        />
      )
    )
  // }

  }


export default Content;



function weatherDataMapper(data){

  const general={
    city:data.city.name,
    country:data.city.country,
    temperature:Math.round(data.list[0].main.temp),
    description:data.list[0].weather[0].description,
    humidity:data.list[0].main.humidity,
    icon:data.list[0].weather[0].icon,
    windSpeed:Math.round(data.list[0].wind.speed*3.6),
    feelsLike:Math.round(data.list[0].main.feels_like),
    code:data.list[0].weather[0].id,


    
  }


  return general;
}