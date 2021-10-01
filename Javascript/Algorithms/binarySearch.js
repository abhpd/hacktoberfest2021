/**
 * Binary search is a searching algorithm that takes an array
 * and a key to search as a parameter to find the element in
 * the array provided.
 *
 * Binary search boasts O(log(n)) Time Complexity making it
 * absurdly fast
 *
 * @param {Number[]} arr - array to search in
 * @param {Number} key - val to find
 * @param {Number} start - starting index
 * @param {Number} end - ending index
 * @returns {Number} index - index of the key
 */

function binarySearch(arr, val, start = 0, end = arr.length - 1) {
  const mid = Math.floor((start + end) / 2);

  if (val === arr[mid]) {
    return mid;
  }

  if (start >= end) {
    return -1;
  }

  return val < arr[mid]
    ? binarySearch(arr, val, start, mid - 1)
    : binarySearch(arr, val, mid + 1, end);
}

// Example execution
let index = binarySearch(
  [1, 3, 4, 5, 3, 45, 54235, 23, 4523, 45, 23, 45, 2, 345, 23, 45],
  3
);

console.log(index);
