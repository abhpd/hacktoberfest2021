import React from 'react';
import ReactDOM from 'react-dom';
import { TextField,
        Card,
        Button,
        Typography,
        CardActions,
        CardContent,
        Grid,
        CardMedia,
        CardActionArea} from '@material-ui/core';
import { makeStyles} from '@material-ui/core/styles';
import Recommendations from './recommendations';
import { WiHumidity,WiStrongWind } from "weather-icons-react";
import Temp from './temperature';


const useStyles=makeStyles({
    card:{
        margin:10,
        backgroundColor:"#f59042",

    },
    media:{
        height:150,
        width:150
    },
    temp:{
        display:"grid",
        textAlign:"right",
        alignItems:"center",
        float:"right"
    },
    tempe:{
        textAlign:"center",
        float:"right",
    },
    icon:{
        alignContent:"center",
        textAlign:"center",
    },
    desc:{
        fontFamily:"monospace",
        fontStyle:"italic",
        fontWeight:"bold",
    },
    description:{
        textAlign:"center",
        marginTop:10
    },
    cel:{
        float:"left",
    },
    humidity:{
        verticalAlign:"bottom",
    }
})


const Mapper=(props)=>{
    const week=["Monday","Tuesday","Wendsday","Thursday","Friday","Saturday","Sunday"];
    var TD="";      //determines if its AM or PM
    const today=new Date();
    const date=today.getDate();
    const hours=today.getHours();
    const minutes=today.getMinutes();
    var dey="";

    if(today.getDay()==0){
        dey=week[today.getDay()];
    }else{
        dey=week[today.getDay()-1];
    }
     
    const code=props.code; //code for the weather recommendations
    var recommendation='';
    if(6<hours && hours<18){
        
        recommendation=Recommendations.map((reco)=>reco.day[code].recommendation);
        
    }else{

        recommendation=Recommendations.map((reco)=>reco.night[code].recommendation);
        
    };

    var time="";

    if(minutes<10){
        time=hours + ":"+0 + minutes;
    }else{
        time=hours+":"+minutes;
    }

    if(today.getHours()<12){
        TD="AM"
    }else{
        TD="PM"
    }
    const classes=useStyles();
    console.log(props.code);
    
    
    console.log(recommendation);


    return(
        <Grid container direction="column">
        <Grid item container>
            <Grid item xs={12}>
        <Card className={classes.card}>
            <CardContent xs={8} sm={12}>
                <Typography variant="h2">
                    {props.city},{props.country}
                </Typography>
                <Typography variant="h6" component="h2">
                    {dey}, {time} {TD}
                </Typography>
                
                <Grid constainer direction="column">
                    <Grid item container xs={12}>
                        <Grid className={classes.temp} item xs={10} sm={6}>
                            <Typography className={classes.tempe} variant="h1" component="h1">
                                     <Temp temp={props.temperature}/>
                            </Typography>
                        </Grid>
                        <Grid className={classes.icon} item xs={12} sm={6}>
                            <CardMedia>
                            <img
                                className={classes.image}
                                src={`http://openweathermap.org/img/wn/${props.icon}@2x.png`}
                                width="175px"
                                height="175px"
                            />
                            </CardMedia>
                        </Grid>

                    </Grid>
                    <Grid item container xs={12} className={classes.meta}>
                        <Grid item xs={12}>
                            <Typography>
                                <WiHumidity size={24} color='#000'className={classes.humidity}/>
                                Humidity {props.humidity}%
                            </Typography>
                        </Grid>
                        <Grid item xs={12}>
                            <Typography>
                                <WiStrongWind size={24} color='#000'className={classes.humidity}/>
                                Wind Speed {props.wind_speed} km/h
                            </Typography>
                        </Grid>
                    </Grid>
                    <Grid item container xs={12} className={classes.description}>
                        <Grid item xs={12}>
                            <Typography className={classes.desc} variant="h4" component="h3">
                                "{recommendation}"
                            </Typography>
                        </Grid>

                    </Grid>

                </Grid>
                

            
            </CardContent>
        </Card>
        </Grid>
        </Grid>
        </Grid>
        
        
    )
}


export default Mapper;
