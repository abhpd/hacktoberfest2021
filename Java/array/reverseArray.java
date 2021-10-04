package array;

public class reverseArray {
	    public static void main(String args[]) 
	    {  int arr[] = {10, 5, 7, 30}, n = arr.length, i=0;
	       System.out.println("Before Reverse");
	       for( i = 0; i < n; i++)
	       		System.out.print(arr[i]+" ");
	       
	       System.out.println();
	       
	       reverse1(arr,i, n);
	       System.out.println("Reverse Method 1: Same Array reverse");
	       for( i = 0; i < n; i++)
	       		System.out.print(arr[i]+" ");
	       System.out.println("\nReverse Method 2: New Array is used\n");
	       int res[]  = reverse2(arr,i,n);
	       for( i=0;i<n;i++)
	    	   System.out.print(res[i]+" ");
	    }
	    static void reverse1(int arr[],int i, int n)
	    {	int low = i, high = n - 1;
	    	while(low < high)
	    	{	int temp = arr[low];
	    		arr[low] = arr[high];
	    		arr[high] = temp;
	    		low++;
	    		high--;
	    	}
	    }
	    static int[] reverse2(int arr[],int i,int n) {
			 int j=n-1;
			int b[] = new int[n];
			for(i=0;i<n;i++) {
				b[j]=arr[i];
				j--;
				if(j<0)
					break;
			}
			return b;
		}

	}