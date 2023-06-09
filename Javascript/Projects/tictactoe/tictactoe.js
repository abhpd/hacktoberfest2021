const gamesheet = document.getElementById('gamesheet');
const boxes = Array.from(document.getElementsByClassName('box'));
const restartBtn = document.getElementById('restartButton');
const playText = document.getElementById("playText");
const spaces = [null, null, null, null, null, null, null, null, null];
const O_TEXT='0';
const X_TEXT='X';
let currentPlayer = X_TEXT;
let winnerDeclared = false;

// selectors
let subtext = document.querySelector('.subtext'); 
// display winner/tie
let playerName = document.querySelector('.player-name'); // purpose: alert player turn

//create gameboard
const drawBoard = () => {
  boxes.forEach((box, index) => {
    let styleString = '';
    if (index < 3) {
      styleString += `border-bottom: 7px solid #fee440;`;
    }
    if (index % 3 === 0) {
      styleString += `border-right: 7px solid #fee440;`;
    }
    if (index % 3 === 2) {
      styleString += `border-left: 7px solid #fee440;`;
    }
    if (index > 5) {
      styleString += `border-top: 7px solid #fee440;`;
    }
    box.style = styleString;
    box.addEventListener('click', boxClicked);
  })
}

//update player direction
function alertNextPlayer() {
  currentPlayer === X_TEXT ? playerName.textContent = 'Player 1' : playerName.textContent = 'Player 2';
}

function boxClicked(e) {
  const id = e.target.id;
  if (!spaces[id]) {
    spaces[id] = currentPlayer;
    e.target.innerText = currentPlayer;
    if (hasPlayerWon(currentPlayer)) {
      playText.innerHTML = `${currentPlayer} wins!!`;
      return;
    }
    currentPlayer = currentPlayer === X_TEXT ? O_TEXT : X_TEXT;
  }
}

//checks if a player has won & notifies
const hasPlayerWon = (player) => {
  if (spaces[0] === player) {
    if (spaces[1] === player && spaces[2] === player) {
      console.log(`${player} wins up top`);
      subtext.innerHTML = `<b>${player} wins on the top!</b>`;
      return true;
    }
    if (spaces[3] === player && spaces[6] === player) {
      console.log(`${player} wins on the left`);
      subtext.innerHTML = `<b>${player} wins on the left!</b>`;
      return true;
    }
    if (spaces[4] === player && spaces[8] === player) {
      console.log(`${player} wins on the diagonal`);
      subtext.innerHTML = `<b>${player} wins on the diagonal!</b>`;
      return true;
    }
  }
  if (spaces[8] === player) {
    if (spaces[2] === player && spaces[5] === player) {
      console.log(`${player} wins on the right`);
      subtext.innerHTML = `<b>${player} wins on the right!</b>`;
      return true;
    }
    if (spaces[7] === player && spaces[6] === player) {
      console.log(`${player} wins on the bottom`);
      subtext.innerHTML = `<b>${player} wins on the bottom!</b>`;
      return true;
    }
  }
  if (spaces[4] === player) {
    if (spaces[3] === player && spaces[5] === player) {
      console.log(`${player} wins on the middle horizontal`);
      subtext.innerHTML = `<b>${player} wins on the middle horizontal!</b>`;
      return true;
    }
    if (spaces[1] === player && spaces[7] === player) {
      console.log(`${player} wins on the middle vertical`);
      subtext.innerHTML = `<b>${player} wins on the middle vertical!</b>`;
      return true;
    }
  }
  if (spaces[2] === player) {
    if (spaces[4] === player && spaces[6] === player) {
      console.log(`${player} wins on the diagonal`);
      subtext.innerHTML = `<b>${player} wins on the diagonal!</b>`;
      return true;
    }
  }
};

//restart button
restartButton.addEventListener("click", () => {
  spaces.forEach((space, index) => {
    spaces[index] = null;
  });
  boxes.forEach((box) => {
    box.innerText = '';
  });
  playText.innerHTML = `Let's Play!!`;

  currentPlayer = X_TEXT;
});

drawBoard();
