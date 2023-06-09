function linearSearch(arr, elem) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === elem) {
            return i;
        }
    }
    return -1;
}

// Tests
let numbers = [2, 5, 7, 8, 10, 13, 14];
console.log(linearSearch(numbers, 5)); // -> 1
console.log(linearSearch(numbers, 8)); // -> 3
console.log(linearSearch(numbers, 14)); // -> 6
console.log(linearSearch(numbers, 6)); // -> -1