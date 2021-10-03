const X = "x";
const CIRCLE = "circle";
const board = document.querySelector(".gameboard");
const cellElements = document.querySelectorAll(".cell");
const text = document.querySelector(".text");
const restartBtn = document.querySelector(".btn");
let circleTurn;
let arr = [];

function restart() {
  board.classList.remove("gameend");
  arr = [];
  startGame();
}

function startGame() {
  circleTurn = false;
  console.log("Game start");
  for (let cell of cellElements) {
    cell.classList.remove(CIRCLE);
    cell.classList.remove(X);
    cell.innerHTML = "";
    text.innerHTML = "Let's Start";
    cell.addEventListener("click", clickHandler, { once: true });
  }
  restartBtn.innerHTML = "Restart";
}

const clickHandler = (key) => {
  const cell = key.target;
  const currentClass = circleTurn ? CIRCLE : X;
  placeSymbol(cell, currentClass);
  text.innerHTML = winningDecission();
  if (text.innerHTML === "X Wins 🏆" || text.innerHTML === "O Wins 🏆")
    endGame();
};

const placeSymbol = (cell, currentClass) => {
  if (currentClass === CIRCLE) {
    cell.innerHTML = "O";
    arr.push("O");
    circleTurn = false;
  } else {
    cell.innerHTML = "X";
    arr.push("X");
    circleTurn = true;
  }
};

function winningDecission() {
  if (arr.length >= 3) {
    if (
      box1.innerHTML != "" &&
      box1.innerHTML == box2.innerHTML &&
      box1.innerHTML == box3.innerHTML
    )
      return box1.innerHTML + " Wins 🏆";
    else if (
      box4.innerHTML != "" &&
      box4.innerHTML == box5.innerHTML &&
      box4.innerHTML == box6.innerHTML
    )
      return box4.innerHTML + " Wins 🏆";
    else if (
      box7.innerHTML != "" &&
      box7.innerHTML == box8.innerHTML &&
      box7.innerHTML == box9.innerHTML
    )
      return box7.innerHTML + " Wins 🏆";
    else if (
      box1.innerHTML != "" &&
      box1.innerHTML == box4.innerHTML &&
      box1.innerHTML == box7.innerHTML
    )
      return box1.innerHTML + " Wins 🏆";
    else if (
      box2.innerHTML != "" &&
      box2.innerHTML == box5.innerHTML &&
      box2.innerHTML == box8.innerHTML
    )
      return box2.innerHTML + " Wins 🏆";
    else if (
      box3.innerHTML != "" &&
      box3.innerHTML == box6.innerHTML &&
      box3.innerHTML == box9.innerHTML
    )
      return box3.innerHTML + " Wins 🏆";
    else if (
      box1.innerHTML != "" &&
      box1.innerHTML == box5.innerHTML &&
      box1.innerHTML == box9.innerHTML
    )
      return box1.innerHTML + " Wins 🏆";
    else if (
      (box3.innerHTML != "") & (box3.innerHTML == box5.innerHTML) &&
      box3.innerHTML == box7.innerHTML
    )
      return box3.innerHTML + " Wins 🏆";
    else {
      if (arr.length != 9) return " Till Now Draw";
      else return " Match Draw";
    }
  } else {
    return "Let's Start";
  }
}
const endGame = () => {
  console.log("Gameend");
  board.classList.add("gameend");
};
restartBtn.addEventListener("click", restart);
