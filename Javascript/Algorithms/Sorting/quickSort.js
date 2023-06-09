function change(items, leftIndex, rightIndex){
    var temp = items[leftIndex];
    items[leftIndex] = items[rightIndex];
    items[rightIndex] = temp;
}
function division(items, left, right) {
    var pivot   = items[Math.floor((right + left) / 2)], //middle element
        i       = left, 
        j       = right;
    while (i <= j) {
        while (items[i] < pivot) {
            i++;
        }
        while (items[j] > pivot) {
            j--;
        }
        if (i <= j) {
            change(items, i, j);
            i++;
            j--;
        }
    }
    return i;
}

function quickSort(items, left, right) {
    var index;
    if (items.length > 1) {
        index = division(items, left, right); 
        if (left < index - 1) {
            quickSort(items, left, index - 1);
        }
        if (index < right) {
            quickSort(items, index, right);
        }
    }
    return items;
}

/**
 * Example:
 */

const array = [0,19,22,75,13,16,12,123,55,2,1,64];

const sortedArray = quickSort(array, 0, array.length - 1);
console.log(sortedArray);
