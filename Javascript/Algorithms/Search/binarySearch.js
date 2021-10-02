function binarySearch(arr, elem) {
    let start = 0;
    let end = arr.length - 1;
    while (start <= end) {
        let mid = (start + end) >> 1; // Midpoint index
        if (arr[mid] > elem) { // Too high
            end = mid - 1;
        } else if (arr[mid] < elem) { // Too low
            start = mid + 1;
        } else { // Found element
            return mid;
        }
    }
    return -1; // Element not in array
}

// Tests
let numbers = [2, 5, 7, 8, 10, 13, 14];
console.log(binarySearch(numbers, 5)); // -> 1
console.log(binarySearch(numbers, 8)); // -> 3
console.log(binarySearch(numbers, 14)); // -> 6
console.log(binarySearch(numbers, 6)); // -> -1