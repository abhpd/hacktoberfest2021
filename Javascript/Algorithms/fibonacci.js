// Takes fibonacci length request as int, returns fibonacci array
// Sample
// let test = fibonacci(5);
// console.log(test);
function fibonacci(n) {
  const fibArray = [1];

  let currentVal = 1;
  let previousVal = 0;

  if (n === 1) {
    return fibArray;
  }

  let counter = n - 1;

  while (counter) {
    currentVal += previousVal;
    previousVal = currentVal - previousVal;

    fibArray.push(currentVal);

    counter -= 1;
  }

  return fibArray;
}
