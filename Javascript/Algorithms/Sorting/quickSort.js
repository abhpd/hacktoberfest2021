function partition(items, left, right) {
    //rem that left and right are pointers.

    let pivot = items[Math.floor((right + left) / 2)],
        i = left, //left pointer
        j = right; //right pointer

    while (i <= j) {
        //increment left pointer if the value is less than the pivot
        while (items[i] < pivot) {
            i++;
        }

        //decrement right pointer if the value is more than the pivot
        while (items[j] > pivot) {
            j--;
        }

        //else we swap.
        if (i <= j) {
            [items[i], items[j]] = [items[j], items[i]];
            i++;
            j--;
        }
    }

    //return the left pointer
    return i;
}

function quickSort(items, left, right) {
    let index;

    if (items.length > 1) {
        index = partition(items, left, right); //get the left pointer returned

        if (left < index - 1) {
            //more elements on the left side
            quickSort(items, left, index - 1);
        }

        if (index < right) {
            //more elements on the right side
            quickSort(items, index, right);
        }
    }

    return items; //return the sorted array
}

let items = [5, 3, 7, 6, 2, 9];

console.log(quickSort(items, 0, items.length - 1));