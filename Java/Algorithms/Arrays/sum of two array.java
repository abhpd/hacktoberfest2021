public class Solution {

    public static void sumOfTwoArrays(int arr1[], int arr2[], int output[]) 
    {
        int sum=0,carry=0,result=0;
        int i=arr1.length-1,j=arr2.length-1,l=output.length-1;
        while(i>-1&&j>-1)
        {   
            sum=carry+arr1[i]+arr2[j];
            result=sum%10;
            output[l]=result;
            carry=sum/10;
            i--;
            j--;
            l--;
        }
        if(carry>0)
        {
        output[l]=carry;
        l--;
        }
        while(i>-1)
        {
            sum=carry+arr1[i];
            result=sum%10;
            output[l]=result;
            carry=sum/10;
            i--;
            l--;
        }
         while(j>-1)
        {
            sum=carry+arr2[j];
            result=sum%10;
            output[l]=result;
            carry=sum/10;
             j--;
             l--;
        }
    }
}
