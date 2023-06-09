var numberofdrumbuttons=document.querySelectorAll(".drum").length;
for(var i=0; i<numberofdrumbuttons; i++ ){
document.querySelectorAll(".drum")[i].addEventListener("click",function (){


makeSound(buttoninnerhtml)

});
 }


 document.addEventListener("keypress", function(event) {
    makesound(event.key);
})

function makesound(key){

    
    var buttoninnerhtml= this.innerHTML 
    switch(key) {
      case "l":
       
       var tom1=new Audio("sounds/tom-1.mp3");
  tom1.play();
     
    
        break;
        case"k":
         var tom2=new Audio("sounds/tom-2.mp3");
  tom2.play();
  break;
  
  case"j":
    var tom3 =new Audio("sounds/tom-3.mp3");
  tom3.play();
  break;
  
  case"d":
    var tom4 =new Audio("sounds/tom-4.mp3");
  tom4.play();
  break;
  case"s":
    var snare =new Audio("sounds/snare.mp3");
  snare.play();
  break;
  case"a":
    var kick =new Audio("sounds/kick-bass.mp3");
  kick.play();
  break;
  case"w":
    var crash =new Audio("sounds/crash.mp3");
  crash.play();
  break;
  
      default: console.log(buttoninnerhtml);
      
    }
}




