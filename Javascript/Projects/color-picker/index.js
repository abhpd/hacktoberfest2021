
const colors = [ "green " , "red " , "salmon" , "hotpink" , "#f15025" , "blue" , "violet" , "gray"];

const btn = document.getElementById('btn');
const color = document.querySelector(".color");

// Adding click event listner on btn
btn.addEventListener('click' , ()=>{
    // Get any random number from array color between 0 and 9 (array index).
    const randomIndx = getRandomNumber();
    console.log(randomIndx);
    
    document.body.style.backgroundColor = colors[randomIndx];
    color.textContent = colors[randomIndx] ;
});

// A function to get random numbers between 0 and length of array colors
function getRandomNumber (){
    return Math.floor(Math.random() * colors.length);
}


