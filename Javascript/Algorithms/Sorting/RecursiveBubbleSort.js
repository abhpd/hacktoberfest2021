// Recursive Bubble Sort

function bubbleSort(arr, n) {
    // Base case
    if (n == 1)
        return;
  
    // One pass of bubble
    // sort. After this pass,
    // the largest element
    // is moved (or bubbled)
    // to end.
     
    for (var i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            // swap arr[i], arr[i+1]
            var temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    // Largest element is fixed,
    // recur for remaining array
    bubbleSort(arr, n - 1);
}
  
// Driver code
var arr = [64, 34, 25, 12, 22, 11, 90 ]
bubbleSort(arr, arr.length);
document.write("Sorted array : " + "<br>");
for(var i = 0; i < arr.length; i++) {
    document.write(arr[i] + " ");
}
