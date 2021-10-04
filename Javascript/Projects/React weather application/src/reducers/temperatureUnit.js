
const tempReducer= (state=false,action) => {   //default state is false. getting an action from action/index.js

    switch(action.type){
        case "change":
            return state=!state;
        default:
            return state;
    }
    
}
export default tempReducer;