#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int BinarySearch(int array[], int numberofElements, int data);

int main()
{
    int numbers[5] = {5,8, 13, 21, 29};

    // array should be a sorted one before it passes to a Binary_SearchMethod
    int result = BinarySearch(numbers, 5, 21);
    printf("%d \n", result);

    return 0;
}

int BinarySearch(int array[], int numberofElements, int data){
    int left= 0;
    int right = numberofElements-1;
    int mid = (left + right)/2;

    while(left<=right){ //if left > right, that means data not found
          if(data == array[mid]){ //CASE 1
            return mid;
          }else if(data < array[mid]){ //CASE 2
            right = mid -1;
          }else if(data > array[mid]){ //CASE 3
            left = mid + 1;
          }
    }
    return -1;


}
