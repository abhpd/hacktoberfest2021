const sumOfDigits = (x) => {
  if(x === 0) return 0;
  let digit = x % 10;
  return digit + sumOfDigits(Math.trunc(x/10));
};

//test 

console.log(sumOfDigits(213))