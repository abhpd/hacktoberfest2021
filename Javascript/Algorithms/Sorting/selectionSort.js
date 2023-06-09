function selectionSort(arr) {
  const swap = (arr, index1, index2) =>
    ([arr[index1], arr[index2]] = [arr[index2], arr[index1]]);

  for (let i = 0; i < arr.length; i++) {
    let lowest = i;
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[lowest] > arr[j]) {
        lowest = j;
      }
    }
    if (i !== lowest) swap(arr, i, lowest);
  }

  return arr;
}

function selectionSort2(array) { // selection sort to stop iteration if array is already sorted.
  for (let i = 0; i < array.length; i++) {
    let minValueIndex = i;
    let alreadySorted = 1;
    for (let j = i + 1; j < array.length; j++) {
      if (array[j] < array[i])
        minValueIndex = j;
      if (array[j] < array[j - 1])
        alreadySorted = 0;
    }
    if (alreadySorted)
      break;
    if (minValueIndex !== i)
      [array[i], array[minValueIndex]] = [array[minValueIndex], array[i]];
  }
  return array;
}


const myArray = [0,4,22,45,12,15,17]
selectionSort(myArray);
selectionSort2(myArray)