const sliderValue = document.querySelector('.slider-value')
const slider = document.querySelector('#grid-size-slider')

sliderValue.innerText = `${slider.value} x ${slider.value}`;
createGrid(slider.value);

slider.addEventListener('input', (e) => {
  sliderValue.innerText = `${e.target.value} x ${e.target.value}`;
  createGrid(e.target.value)
})

function createGrid(gridSize) {
  const canvas = document.querySelector(".canvas");
  canvas.innerHTML = "";
  for(let i = 0; i < gridSize; i++){
    let rowDiv = document.createElement('div')
    rowDiv.classList.add("canvas-row")
    for(let j = 0; j< gridSize; j++){
      let div = document.createElement("div")
      div.className = ["grid-cell"];
      div.addEventListener("mouseenter", changeCellColor)
      div.style.backgroundColor = "rgb(255, 255, 255)";
      rowDiv.appendChild(div);
    }
    canvas.appendChild(rowDiv);
  }
}

function changeCellColor(e){
  if(colorMode === 'rgb'){
    currentColor = chooseRandomColor();
  }
  if(colorMode === 'gray'){
    let cellColor = e.target.style.backgroundColor;
    let c = parseInt(cellColor.slice(4,7)) - 20;
    if(c < 50) c = 50;
    currentColor = `rgb(${c}, ${c}, ${c})`;
  }
  e.target.style.backgroundColor = currentColor;
}


let colorMode = "black";
let currentColor = "black"

const colorModeChooser = document.querySelectorAll('.color-mode-chooser');

colorModeChooser.forEach((button) => {
  button.addEventListener("click", (e) => {
    if(e.target.name === "gray"){
      colorMode = "gray";
      currentColor = "rgb(215, 215, 215)";
      removeActiveClass(e.target.name);
      e.target.classList.add('active');
    } else if(e.target.name === "eraser") {
      colorMode = "eraser";
      currentColor = "rgb(255, 255, 255)"
      removeActiveClass(e.target.name);
      e.target.classList.add('active');
    } else if (e.target.name === "rgb"){
      colorMode = "rgb";
      currentColor = chooseRandomColor();
      removeActiveClass(e.target.name); 
      e.target.classList.add('active');
    }
  });
});

function removeActiveClass(name){
  colorModeChooser.forEach((button) => {
    if(button.name !== name){button.classList.remove('active')}
  })
}

const colorPicker = document.querySelector("#favcolor")
colorPicker.addEventListener("change", (e) => {
  removeActiveClass(e.target.name)
  colorMode = "userColor"
  currentColor = e.target.value
})

function chooseRandomColor(){
  let r = Math.floor(Math.random() * 255);
  let g = Math.floor(Math.random() * 255);
  let b = Math.floor(Math.random() * 255);
  return `rgb(${r}, ${g}, ${b})`;
}

function resetGrid(){
  createGrid(sliderValue.innerText.slice(0,2))
}