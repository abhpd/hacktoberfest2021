// Loop through the array of numbers
// At each iteration, if a number is evenly divisible by 3 print "Fizz"
// If a number is evenly divisible by 5 print "Buzz"
// If a number is evenly divisible by both 3 AND 5, print "Fizz Buzz"
// If a number is not divisible by 3 or 5, print the number

var fizzBuzz = function(arr) {
    for (var i = 0; i < arr.length; i++) {
      var currentNumber = arr[i];
  
      if (currentNumber % 15 === 0) {
        console.log("Fizz Buzz");
      } else if (currentNumber % 3 === 0) {
        console.log("Fizz");
      } else if (currentNumber % 5 === 0) {
        console.log("Buzz");
      } else {
        console.log(currentNumber);
      }
    }
  };
  