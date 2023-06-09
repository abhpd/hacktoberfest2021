// finding the partition index 
function partition(arr, b, e) {
    let pivot = arr[e];
    let bigIndex = b;
    for (let i = b; i < e; i++) {
        if (arr[i] < pivot) {
            let t = arr[bigIndex];
            arr[bigIndex++] = arr[i];
            arr[i] = t;
        }
    }

    let t = arr[bigIndex];
    arr[bigIndex] = arr[e];
    arr[e] = t;
    return bigIndex;
}

function quickSortImpl(arr, b, e) {
    if (b < e) {
        let p = partition(arr, b, e);
        quickSortImpl(arr, b, p-1);
        quickSortImpl(arr, p+1, e);
    }
}

function quickSort(inputArr) {
    quickSortImpl(inputArr, 0, inputArr.length-1);
    return inputArr;
}

const myArray = [0,4,22,45,12,15,17,4,7,123,55,2,1,44];
console.log(quickSort(myArray));
