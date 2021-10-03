import java.util.*;  
public class BucketSortExample2  
{  
//user-defined method that sorts the array elements   
   
static int[] bucketSort(int[] array, int maxValue)   
{  
//createsa buckets array  

int[] Bucket = new int[maxValue + 1];  
//creating an array for storing the sorted elements  
int[] sorted_array = new int[array.length]; 
 
for (int i = 0; i < array.length; i++)  
Bucket[array[i]]++;  
int outPos = 0;  

for (int i = 0; i < Bucket.length; i++)  
for (int j = 0; j < Bucket[i]; j++)
  
sorted_array[outPos++] = i;  

//returns sorted array  

return sorted_array;  
}   
//method that prins the array elements   
static void printArray(int[] sorted_array)   
{  
for (int i = 0; i < sorted_array.length; i++)  
System.out.print(sorted_array[i] + " ");  
}  
//method finds the maximum elements of the array and returns the same  
static int maxValue(int[] array)   
{  
int maxValue = 0;  

for (int i = 0; i < array.length; i++)  
if (array[i] > maxValue)  
maxValue = array[i];  
return maxValue;  
}  

//driver code  
public static void main(String args[])   
{  

System.out.println("Sorted array after performing bucket sort:");  

Random random = new Random();  
//the number of elements to be randomly generate  
int N = 12;  

//creating an array of randomly generated numbers (N) 
 
int[] array = new int[N];  

for (int i = 0; i < N; i++)  

//generates random numbers within specified range i.e. 40  

array[i] = Math.abs(random.nextInt(40)); 
 
//determines the maximum value in the array  
int maxValue = maxValue(array);
  
System.out.println("\nUn-sorted Array: ");  

//prints un-sorted array  

printArray(array);  
System.out.println("\nSorted Array: ");  

//prints sorted array  
printArray(bucketSort(array, maxValue));  
}  
}  