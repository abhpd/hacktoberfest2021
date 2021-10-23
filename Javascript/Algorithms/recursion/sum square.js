const sumsSquare = (arr) =>{
  if(arr.length === 0) return 0;
  let rest = arr.slice(1)
  return Math.pow(arr[0],2) + sumsSquare(rest)
};

let array = [1,2,3,4]

//test

console.log(sumsSquare(array))