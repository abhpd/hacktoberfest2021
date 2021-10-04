package array;

public class Smallest_Positive_missing_number {
	public static void main(String args[]) {
		int arr[] = {-2, -2,12, 5,1,8,  -9};
		int res = missingNumber(arr,arr.length);
		System.out.println("Ans "+res);
	}
	
	static int missingNumber(int arr[], int size)
    {   int res=1;
        int a[]=new int[size];
        int n = size;
       int j=0;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                a[j] = arr[i];
                j++;
            }
        }
        int temp=0;
    
        temp = a[0]; if(temp<1)	return 1;
        for(int i=1;i<j;i++){
            if(a[i] != temp+1 &&a[i]!=temp)    return temp+1;
            temp = a[i];
        }
        res = a[j-1];
        
        return res+1;
    }
	
}

