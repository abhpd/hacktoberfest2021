const countingSort = (arr, size, place) => {
  
    let output = new Array(size + 1).fill(0);
    let max = Math.max(...arr);
    
    let freq = new Array(max + 1).fill(0);
    
    // Calculate count of elements
    for (let i = 0; i < size; i++){
        const num = Math.floor(arr[i] / place) % 10;
        freq[num]++;
    }
    
    // Calculate cummulative count
    for (let i = 1; i < 10; i++){
        freq[i] += freq[i - 1];
    }
  
    // Place the elements in sorted order
    for (let i = size - 1; i >= 0; i--) {
        const num = Math.floor(arr[i] / place) % 10;
        output[freq[num] - 1] = arr[i];
        freq[num]--;
    }
    
    //Copy the output array
    for (let i = 0; i < size; i++){
      arr[i] = output[i];
    }
  }
  
  const radixSort = (arr, size = arr.length) => {
    //Get the max element
    let max = Math.max(...arr);
    
    //Sort the array using counting sort
    for(let i = 1; parseInt(max / i) > 0; i *= 10){
      countingSort(arr, size, i);
    }
  }