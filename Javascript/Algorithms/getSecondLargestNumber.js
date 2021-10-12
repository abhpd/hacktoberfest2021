function print2largest(arr, arr_size) {
        let i, first, second;
  
        // There should be atleast two elements
        if (arr_size < 2) {
            console.log(" Invalid Input ");
            return;
        }
  
        // sort the array
        arr.sort();
  
        // start from second last element
        // as the largest element is at last
        for (i = arr_size - 2; i >= 0; i--) {
            // if the element is not
            // equal to largest element
            if (arr[i] != arr[arr_size - 1]) {
                console.log("The second largest element is " + arr[i]);
                return;
            }
        }
  
        console.log("There is no second largest element<br>");
 }
