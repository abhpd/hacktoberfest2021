const arrayProduct = (arr) => {
  if(arr.length === 0){
    return 0
  }else if(arr.length === 1){
    return arr[0]
  }else{
    let rest = arr.slice(1);
    return arr[0] * arrayProduct(rest)
  }
};

// test

let array = [1,2,3,4,5,5]

console.log(arrayProduct(array))