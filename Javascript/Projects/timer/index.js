const startButton=document.querySelector('#start');
const pauseButton=document.querySelector('#pause');
const duration=document.querySelector('#duration');

const circle=document.querySelector('circle');
const perimeter=circle.getAttribute('r')*2*Math.PI;
circle.setAttribute('stroke-dasharray',perimeter);

let currentDuration;

const timer= new Timer(duration,startButton,pauseButton,{
    onStart(totalDuration){
        console.log("Timer started!!");
        currentDuration=totalDuration;
    },
    onTick(timeleft){
        circle.setAttribute('stroke-dashoffset',
        perimeter*timeleft/currentDuration-perimeter);
    },
    onComplete(){
        console.log("Timer completed !!!")
        circle.setAttribute('stroke-dashoffset',-perimeter);
    }

});