const e0=document.getElementById("e0");
const e1=document.getElementById("e1");
const e2=document.getElementById("e2");
const e3=document.getElementById("e3");
const e4=document.getElementById("e4");
const e5=document.getElementById("e5");
const e6=document.getElementById("e6");
const e7=document.getElementById("e7");
const e8=document.getElementById("e8");

let gameboard=["","","","","","","","",""];
let count=0;

e0.addEventListener("click",()=>{
    if (gameboard[0]===""){
    gameboard[0]=switchplayer();
    showboard(gameboard);
    checkwinner(gameboard);
}
});
e1.addEventListener("click",()=>{
    if (gameboard[1]===""){
        gameboard[1]=switchplayer();
        showboard(gameboard);
        checkwinner(gameboard);
    }
});
e2.addEventListener("click",()=>{
    if (gameboard[2]===""){
        
        gameboard[2]=switchplayer();
        showboard(gameboard);
        checkwinner(gameboard);
    }
});
e3.addEventListener("click",()=>{
    if (gameboard[3]===""){
        
        gameboard[3]=switchplayer();
        showboard(gameboard);
        checkwinner(gameboard);
    }
});
e4.addEventListener("click",()=>{
    if (gameboard[4]===""){
        
        gameboard[4]=switchplayer();
        showboard(gameboard);
        checkwinner(gameboard);
    }
});
e5.addEventListener("click",()=>{
    if (gameboard[5]===""){
        
        gameboard[5]=switchplayer();
        showboard(gameboard);
        checkwinner(gameboard);
    }
});
e6.addEventListener("click",()=>{
    if (gameboard[6]===""){
        gameboard[6]=switchplayer();
        showboard(gameboard);
        checkwinner(gameboard);
        
    }
});
e7.addEventListener("click",()=>{
    if (gameboard[7]===""){
        gameboard[7]=switchplayer();
        showboard(gameboard);
        checkwinner(gameboard);
        
    }
});
e8.addEventListener("click",()=>{
    if (gameboard[8]===""){
        gameboard[8]=switchplayer();
        showboard(gameboard);
        checkwinner(gameboard);

    }
});

function showboard(gameboard){
   e0.innerText=gameboard[0];
   e1.innerText=gameboard[1];
   e2.innerText=gameboard[2];
   e3.innerText=gameboard[3];
   e4.innerText=gameboard[4];
   e5.innerText=gameboard[5];
   e6.innerText=gameboard[6];
   e7.innerText=gameboard[7];
   e8.innerText=gameboard[8];

    // console.log(gameboard);
}

function switchplayer(){
    count++;
    if (count>=9){
        gamereset();
        document.getElementById("win").innerText=gameboard[2]+" Game Draw";
    }
    if (count%2==0){
        document.getElementById("player").innerText="Player : "+"X";
        return "0";
    }
    else{
        document.getElementById("player").innerText="Player : "+"0";
        return "X";
    }


}

function checkwinner(gameboard){
    if (gameboard[0]==gameboard[1] && gameboard[0]==gameboard[2]){
        if(gameboard[0]!=""){
            document.getElementById("win").innerText=gameboard[0]+" Player Won";
            setTimeout(() => {
                gamereset();
            }, 2000);

        }
    }
    else if (gameboard[3]==gameboard[4] && gameboard[3]==gameboard[5]){
        if(gameboard[3]!=""){
            document.getElementById("win").innerText=gameboard[3]+" Player Won";
            setTimeout(() => {
                gamereset();
            }, 2000);
        }
    }
    else if (gameboard[6]==gameboard[7] && gameboard[6]==gameboard[8]){
        if(gameboard[6]!=""){
            document.getElementById("win").innerText=gameboard[6]+" Player Won";
            setTimeout(() => {
                gamereset();
            }, 2000);
        }
    }
    else if (gameboard[0]==gameboard[3] && gameboard[0]==gameboard[6]){
        if(gameboard[0]!=""){
            document.getElementById("win").innerText=gameboard[0]+" Player Won";
            setTimeout(() => {
                gamereset();
            }, 2000);
        }
    }
    else if (gameboard[1]==gameboard[4] && gameboard[1]==gameboard[7]){
        if(gameboard[1]!=""){
            document.getElementById("win").innerText=gameboard[1]+" Player Won";
            setTimeout(() => {
                gamereset();
            }, 2000);
        }
    }
    else if (gameboard[2]==gameboard[5] && gameboard[2]==gameboard[8]){
        if(gameboard[2]!=""){
            document.getElementById("win").innerText=gameboard[2]+" Player Won";
            setTimeout(() => {
                gamereset();
            }, 2000);
        }
    }
    else if (gameboard[0]==gameboard[4] && gameboard[0]==gameboard[8]){
        if(gameboard[0]!=""){
            document.getElementById("win").innerText=gameboard[0]+" Player Won";
            setTimeout(() => {
                gamereset();
            }, 2000);
        }
    }
    else if (gameboard[2]==gameboard[4] && gameboard[2]==gameboard[6]){
        if(gameboard[2]!=""){
            document.getElementById("win").innerText=gameboard[2]+" Player Won";
            setTimeout(() => {
                gamereset();
            }, 2000);
        }
    }
}


function gamereset(){
    gameboard=["","","","","","","","",""];
    count=0;
    setTimeout(() => {
        showboard(gameboard);
        document.getElementById("win").innerText="";
        document.getElementById("player").innerText="Player : X";
        
    }, 2000);

}