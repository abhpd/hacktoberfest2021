//Game values
let min = 1, 
    max = 10,
    winningNum = getRandomNum(min, max),
    guessLeft = 3;

//UI elements
const game = document.querySelector('#game'),
    minNum = document.querySelector('.min-num'),
    maxNum = document.querySelector('.max-num'),
    guessBtn = document.querySelector('#guess-btn'),
    guessInput = document.querySelector('#guess-input'),
    message = document.querySelector('.message');

//Assign UI min max
minNum.textContent = min;
maxNum.textContent = max;

//play again event listener
game.addEventListener('mousedown', function(e){
    if(e.target.className === 'play-again'){
        window.location.reload();
    }
})

//listen for guess
guessBtn.addEventListener('click', function(){
    let guess = parseInt(guessInput.value);

    //validation
    if (isNaN(guess) || guess < min || guess > max){
        setMessage(`Please enter a number between ${min} and ${max}`, 'red');
    }else{

        if(guess === winningNum){
            gameOver(true, `${winningNum} is correct, YOU WIN!`);
        }
        else{
            guessLeft -= 1;
            if(guessLeft === 0){
                gameOver(false, `Game Over, you lost. The correct number was ${winningNum}`);
                
            }
            else{
                guessInput.style.borderColor = 'red';

                guessInput.value = '';
                setMessage(`${guess} is not correct, ${guessLeft} guesses left`, 'red');
            }
        }
    }
});


//game over
function gameOver(won, msg){
    let color;
    won === true ? color = 'green' : color = 'red';

    guessInput.disabled = true;
    guessInput.style.borderColor = color;
    setMessage(msg, color);    

    guessBtn.value = 'Play Again';
    guessBtn.className += 'play-again';
    
}

//Get winning number
function getRandomNum(min, max){
    return (Math.floor(Math.random()*(max-min+1)+min));
}

//set message
function setMessage(msg, color){
    message.textContent = msg;
    message.style.color = color;
}