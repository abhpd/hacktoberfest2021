let correctNumber = randomNumber();
let guessHistory = [];

console.log(correctNumber);

window.onload = function() {
    document.getElementById("number-submit").addEventListener('click', playGame);
    document.getElementById("restart").addEventListener('click', reset);
}

function playGame() {
    let numberGuess = document.getElementById("number-guess").value;
    displayResult(numberGuess);
    getGuessHistory(numberGuess);
    displayHistory();
    total();
};

function displayResult(numberGuess) {
    if (numberGuess == correctNumber) {
        youWon();
    } else if (numberGuess > correctNumber) {
        numberAbove();
    } else if (numberGuess < correctNumber) {
        numberBelow();
    }
}

function randomNumber() {
    let randomNumber = Math.floor(Math.random() * 100 + 1);
    return randomNumber;
}

function getDialog(status, text) {
    let dialoge;

    switch (status) {
        case "won":
            dialoge = "<div class='alert alert-success'>";
            break;

        case "warning":
            dialoge = "<div class='alert alert-warning'>";
            break;
    }

    dialoge += text;
    dialoge += "</div>";
    return dialoge;
}

function youWon() {
    const text = "Congratulations , You Guessed it Right !";
    let dialog = getDialog("won", text);
    document.getElementById("results").innerHTML = dialog;
}

function numberAbove() {
    const text = "Your Guess is Too High";
    let dialog = getDialog("warning", text);
    document.getElementById("results").innerHTML = dialog;
}

function numberBelow() {
    const text = "Your Guess is Too Low";
    let dialog = getDialog("warning", text);
    document.getElementById("results").innerHTML = dialog;
}

function getGuessHistory(guess) {
    guessHistory.push(guess);
};

function displayHistory() {
    let list = "<ul class='list-group'>"
    let index = guessHistory.length - 1;

    while (index >= 0) {
        list += "<li class='list-group-item'>" + "You guessed " + guessHistory[index] + "</li>";
        index -= 1;
    }
    list += "</ul>"
    document.getElementById("history").innerHTML = list;
}

function total() {
    let total = "<div class='alert alert-dark'>";
    total += "Total Guesses Are - "
    total += guessHistory.length;
    total += '</div>'

    document.getElementById("total").innerHTML = total;
}

function reset() {
    correctNumber = randomNumber();
    document.getElementById("results").innerHTML = "";
    guessHistory = [];
    displayHistory();
    document.getElementById("total").innerHTML = "";
};