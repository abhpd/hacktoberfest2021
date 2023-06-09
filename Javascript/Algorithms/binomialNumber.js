function factorial(n){
    let result = 1;
    while(n>0){
        result*=n
    }
    return result;
}

//Takes n and m as integers, with n>m, returns the binomial number n!/(m!(n-m)!)
function binomialNumber(n,m){
    return factorial(n)/(factorial(n-m)*factorial(m));
}
//Sample
//let test = binomialNumber(15,5)
//console.log(test)