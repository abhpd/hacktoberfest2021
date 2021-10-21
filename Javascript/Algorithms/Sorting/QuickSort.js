// Quick Sort in JavaScript

function partition(arr, low, high)
    {
        let temp;
        let pivot = arr[high];
   
        // index of smaller element
        let i = (low - 1);
        for (let j = low; j <= high - 1; j++) {
   
            // If current element is
            // smaller than or
            // equal to pivot
            if (arr[j] <= pivot) {
                i++;
   
                // swap arr[i] and arr[j]
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
   
        // swap arr[i+1] and arr[high]
        // (or pivot)
        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
   
        return i + 1;
    }

function qSort(arr, low, high)
    {
        if (low < high) {
            /* pi is partitioning index,
            arr[pi] is now at right place */
            let pi = partition(arr, low, high);
   
            // Recursively sort elements
            // before partition and after
            // partition
            qSort(arr, low, pi - 1);
            qSort(arr, pi + 1, high);
        }
    }
     
    let n = 5;
    let arr = [ 4, 2, 6, 9, 2 ];
 
    qSort(arr, 0, n - 1);
 
    for (let i = 0; i < n; i++)
      document.write(arr[i] + " ");
