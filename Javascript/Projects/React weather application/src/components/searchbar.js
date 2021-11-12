import React,{ useState,useEffect } from 'react';
import Cities from './citylist';
import Autocomplete from '@material-ui/lab/Autocomplete';
import TextField from '@material-ui/core/TextField';
import Content from './content';
import SearchIcon from '@material-ui/icons/Search';
import { Grid,IconButton,Input } from '@material-ui/core';
import { makeStyles } from '@material-ui/core/styles';



const useStyles=makeStyles({

  searchbar:{
    alignContent:"center",
  },
  seIcon:{
    
    position:"relative",
    padding:10,
    top:22
  },
  card:{
    backgroundColor:"red",
  }
});

const SearchBar=()=>{

  const classes=useStyles();

  const [city,setcity]=useState("Kurunegala");
  const [apii,setapi]=useState(``);
  const [town,settown]=useState("");
  
 

    const apiFtecher = e => {
      settown(e.target.value);
     }

     function APIsetter(){
       return(
         setcity(town)
       )
     } 


  useEffect(()=>{
    setapi(`https://api.openweathermap.org/data/2.5/forecast?q=${city},LK&mode=json&appid=${yourApiIdFromOpenWeatherApi}`)
  },[city])


    return (
      <div>
      <Grid container >
      <Grid item container xs={12}>
        <Grid item xs={1} sm={2}/>
      <Grid className={classes.searchbar} item xs={12}>
        <Grid container direction="column">
          <Grid item container>
            <Grid item xs={2}/>
          <Grid item xs={8} sm={8}>
      <Autocomplete
        id="free-solo-2-demo"
        disableClearable
        options={Cities.map((option) => option.name)} 
        renderInput={(params) => (
          <div
          >
          <TextField
            id="standard-basic" 
            {...params}
            label="Enter your city"
            margin="normal"
            InputProps={{ ...params.InputProps, type: 'search' }}
            // onChange={apiFtecher}
            onBlur={apiFtecher}
          />
          
      </div>
        )}
      />
      </Grid>
      <Grid className={classes.seIcon} item xs={1}>
        <div onClick={APIsetter}>
            <IconButton>
                <SearchIcon/>
            </IconButton>
        </div>
      </Grid>
      <Grid item xs={1}/>
      </Grid>
      </Grid>
      </Grid>
      <Grid item xs={12} >
      <Content api={apii}/>
      </Grid>
        
    
    </Grid>
    <Grid item xs={1} sm={2}/>
    </Grid>
    </div>
    );

}

export default SearchBar;