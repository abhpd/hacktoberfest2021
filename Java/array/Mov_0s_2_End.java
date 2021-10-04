package array;

public class Mov_0s_2_End {
	public static void main(String[] args) {
		int arr[] = {2,1,0,13,0,0,7,91,0,8};
		int n =arr.length;
		System.out.println("Array : ");
	       for(int i = 0; i < n; i++)
	       		System.out.print(arr[i]+" ");
	    System.out.println("\nMoving 0s to the end : ");
	    int res[] = eff_mov0s(arr);
	    for(int i = 0; i < n; i++)
       		System.out.print(res[i]+" ");
	}
	static int[] eff_mov0s(int arr[]) {
		int n = arr.length,count = 0,temp=0;
		for(int i=0;i<n;i++) {
			if(arr[i] !=0) {
				temp = arr[count];
				arr[count] = arr[i];
				arr[i] =temp;
				count++;
			}
		}
		return arr;
	}
///////// loop run twice
	static int[] movZeros(int arr[]) 
	{	int n = arr.length,i,res=0;
		for(i=0;i<n;i++)
		{	if(arr[i]!=0) {
				arr[res] = arr[i];
				res++;
			}
		}
		for(i=res;i<n;i++) {
			arr[i]=0;
		}
		return arr;
	}
}
