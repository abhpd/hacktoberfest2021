const pow = (x,n) => {
  if(n === 0){
    return 1
  }else if(n > 0){
    return x * pow(x,n-1)
  }else{
    return 1 / (x * pow(x,(-n)-1)) 
  }
}

// test 
console.log(pow(4,-2)) 