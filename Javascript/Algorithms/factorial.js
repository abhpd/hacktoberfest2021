// Takes num as int, returns factorialized value
function factorialize(num) {
    if(num < 0)
        return -1;
    else if (num == 0)
        return 1;
    else 
        return (num  * factorialize(num - 1));
    
}

// sample
// let test = factorialize(5);
// console.log(test);
