function bubbleSort(inputArr) {
  let inputLength = inputArr.length;
  let swapped;
  do {
    swapped = false;
    for (let i = 0; i < inputLength; i++) {
      if (inputArr[i] > inputArr[i + 1]) {
        let temp = inputArr[i];
        inputArr[i] = inputArr[i + 1];
        inputArr[i + 1] = temp;
        swapped = true;
      }
    }
  } while (swapped);
  return inputArr;
}

const myArray = [0,4,22,45,12,15,17,4,7,123,55,2,1,44]
console.log(bubbleSort(myArray))

