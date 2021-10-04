import tempReduser from './temperatureUnit';
import { combineReducers } from 'redux';


const allReducers= combineReducers({
    tempSwitch:tempReduser     //export the tempReducer function as tempSwitch
})

export default allReducers;