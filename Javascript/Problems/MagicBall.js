//Author: Narayanan
//Language: Javascript
//GitHub id: TheProgrammingShinigami

//Initializing a variable with value 'Jane'
let userName = 'Jane';
//if usernmae is null then we print Hello! or Hello, username
userName ? console.log(`Hello, ${userName}!`):console.log('Hello!');

const userQuestion = 'what';
console.log(`${userName} asked: ${userQuestion}`);

//getting a random number
let randomNumber = Math.floor(Math.random() * 8);
let eightBall = '';

//switch block to assign a string from random numebr to eightBall variable
switch(randomNumber) {
  case 0:
    eightBall = 'It is certain';
    break;
  case 1:
    eightBall = 'It is decidedly so';
    break;
  case 2: 
    eightBall = 'Reply hazy try again';
    break;
  case 3:
    eightBall = 'Cannot predict now';
    break;
  case 4:
    eightBall = 'Do not count on it';
    break;
  case 5:
    eightBall = 'My sources say so';
    break;
  case 6:
    eightBall = 'Outlook not so good';
    break;
  case 7:
    eightBall = 'Signs point to yes';
    break;
  case 8:
    eightBall = 'Its gonna be a good day';
    break;
}
//print eightBall to console
console.log(eightBall);
