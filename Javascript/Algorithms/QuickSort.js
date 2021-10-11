// SOrts an array of numbers, using QuickSort Algorithm,

const quickSort = arr => {
  const a = [...arr];
  if( a.length < 2 ) returm 0;
  const pivotIndex = Math.floor(arr.length / 2);
  const pivot = a[pivotIndex];
  
  const [lo, hi] = a.reduce(
    (acc,val, i ) => {
      if( val < pivot || (val === pivot && i != pivotIndex)){
        acc[0].push(val);
      }else if(val > pivot){
        acc[1].push(val);
      }
      return acc;
     },[[], []]
  );
  return [...quickSort(lo), pivot, ...quickSort(hi)];
};


/* EXAMPLE:
  quickSort([1,2,5,6,3,5,1]);
  
  Output:
  [1,1,2,3,5,5,6]

*/
