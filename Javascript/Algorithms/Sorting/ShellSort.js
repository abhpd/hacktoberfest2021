//Shell Sort
//mrSidSat

//create a function for shell sort

function ShellSort(array/*array as a parameter*/)
{
     let temp,gap,i,swapped; //declare required variable local to function to save heap space
     gap = arr.length / 2; //declare the gap which we gonna reduce gradually
     do{
         do{
             swapped =0;
             for(i=0;i<arr.length - gap;i++)
             {
                 if(arr[i]>arr[i+gap])
                 {
                     temp = arr[i];
                     arr[i] = arr[i+gap];
                     arr[i+gap] = temp;
                     swapped = 1; 
                 }
             }
         }while(swapped == 1)//checked whether swapp has been done if yes move on ...
     }while((gap = gap/2)>=1);//gap is being reduced
}

const arr = [1,23,90,12,2,7];//example for usage
ShellSort(arr);//function call
//now array has been sorted
console.log(arr);//check the result


/*
Complexity =>  O(log(nlog^2(n)) < complexity < O(n^(1.5))
*/



//Shell Sort done successfully :)