let userScore = 0;
let computerScore = 0;

// user and computer score
const userScore_span = document.getElementById('user-score');
const computerScore_span = document.getElementById('computer-score');

// scoreboard and result
const scoreBoard = document.querySelector('.score-board');
const result = document.querySelector('.result > p');

// action buttons
const rock = document.getElementById('r');
const paper = document.getElementById('p');
const scissors = document.getElementById('s');

function getComputerChoice() {
    const choices = ['r', 'p', 's'];
    const randomNumber = Math.floor(Math.random() * choices.length);
    return choices[randomNumber];
}

function convertToWord(letter) {
    if (letter === 'r')
        return 'Rock';
    if (letter === 'p')
        return 'Paper';
    if (letter === 's')
        return 'Scissor';
}

function win(userChoice, computerChoice) {
    const smallUserWord = 'User'.fontsize(3).sub();
    const smallCompWord = 'Comp'.fontsize(3).sub();
    const refUserChoice = document.getElementById(userChoice);

    userScore++;
    userScore_span.textContent = userScore;


    result.innerHTML = `${convertToWord(userChoice)} ${smallUserWord} beats ${convertToWord(computerChoice)}${smallCompWord}. You win! 🔥`;

    // styling for winner.
    refUserChoice.classList.add('green-glow');
    setTimeout(() => refUserChoice.classList.remove('green-glow'), 300);
}

function lose(userChoice, computerChoice) {
    const smallUserWord = 'User'.fontsize(3).sub();
    const smallCompWord = 'Comp'.fontsize(3).sub();
    const refUserChoice = document.getElementById(userChoice);

    computerScore++;
    computerScore_span.textContent = computerScore;


    result.innerHTML = `${convertToWord(computerChoice)} ${smallCompWord} beats ${convertToWord(userChoice)} ${smallUserWord}. Oops You loose!`;

    // styling for winner.
    refUserChoice.classList.add('red-glow');
    setTimeout(() => refUserChoice.classList.remove('red-glow'), 300);
}

function draw(userChoice) {
    const refUserChoice = document.getElementById(userChoice);

    result.innerHTML = `Both chooses ${convertToWord(userChoice)}. Its a draw!`;

    // styling for winner.
    refUserChoice.classList.add('gray-glow');
    setTimeout(() => refUserChoice.classList.remove('gray-glow'), 300);
}

function game(userChoice) {
    const computerChoice = getComputerChoice();

    switch (userChoice + computerChoice) {
        case 'rs':
        case 'pr':
        case 'sp':
            win(userChoice, computerChoice);
            break;
        case 'rp':
        case 'ps':
        case 'sr':
            lose(userChoice, computerChoice);
            break;
        case 'rr':
        case 'pp':
        case 'ss':
            draw(userChoice);
            break;
    }
}

// click listeners for rock paper scissors button
function main() {
    rock.addEventListener('click', () => game('r'));

    paper.addEventListener('click', () => game('p'));

    scissors.addEventListener('click', () => game('s'));
}

main();


