//ShellSort
//mrSidSat


#include<iostream>//including header file
using namespace std;
void ShellSort(int arr[],int n) //declared the ShellSort function
{
    int temp,gap,i,swapped; //declare variables
    gap = n/2; // declare gap which we gonna adjust later
    do{
        do{
            swapped =0;
            for(i=0;i<n-gap;i++)
            {
                if(arr[i]>arr[i+gap])
                {
                    temp = arr[i];
                    arr[i] = arr[i+gap];
                    arr[i+gap] = temp;
                    swapped = 1;
                }
            }
        }while(swapped ==1);//check whether swapped happened or not if yes proceed
}while((gap = gap/2)>=1);
}
int main()
{
    int arr[5] = {12,1,45,22,90}; // trial array declaration
    ShellSort(arr,5); //function call
    for(int i = 0;i<5;i++)
    {
        cout<<arr[i]<<" "; // visual output
    }
    return 0; // return to check whether the program executed successfully
}

/*
complexity between O(n log^2(n)) and O(n^(1.5))
*/
//ShellSort done successfully :)

