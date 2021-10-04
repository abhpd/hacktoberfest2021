const sumOfArray = (arr) => {
  if(arr.length === 0){
    return 0;
  }else{
    let rest =  arr.slice(1);
    return arr[0] + sumOfArray(rest);
  }
};

//test

let array = [1,5,5,5,5];
console.log(sumOfArray(array))