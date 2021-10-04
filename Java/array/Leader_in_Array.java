package array;

public class Leader_in_Array {

	public static void main(String[] args) {
		int arr[] = {1,2,8,2,5,4};
		int n =arr.length;
		System.out.println("Array : ");
	       for(int i = 0; i < n; i++)
	       		System.out.print(arr[i]+" ");
	       System.out.println("\nLeaders are : ");
	       
		    int count = leader(arr); //System.out.println(res);
		    int res[] = reverse(arr,count);
		    for(int i=0;i<count;i++)
		    	System.out.print(res[i]+" ");
	}
	///////////////best n times                           prints in reverse order
	static int leader(int arr[]) {
		int n=arr.length;
		int temp[] = new int[n],count=0;
		temp[count] = arr[n-1];
		
		for(int i=n-2;i>=0;i--) {
			if(temp[count]<arr[i]) {
				count++;
				temp[count] = arr[i];
			
			}
		}
		for(int i=0;i<count+1;i++)
			arr[i]=temp[i];
		return count+1;
	}
	static int[] reverse(int arr[],int n) {
		int l=0,temp,r=n-1;
		while(l<r) {
			temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
			l++;
			r--;
		}
		return arr;
	}
	
	//////// naive solution  n2 times 
	static int naive_leader(int arr[]) {
		int n=arr.length,count=0;
		for(int i=0;i<n;i++) {
			boolean flag = true;
			for(int j=i+1;j<n;j++) {
				if(arr[i] < arr[j]) 
					flag = false;
			}
			if(flag) {
				arr[count] = arr[i];
				count++;
			}
		}
		
		return count;
	}
	/////////////////////////////////////////////// n2 times and n space
	static int leader_Anik(int arr[]) {
		int count = 0,n =arr.length;
		int b[] = new int[n];
		for(int i=0;i<n-1;i++) {
			for(int j=i+1;j<n;j++) {
				if(arr[i]>arr[j]) {
					b[i] = arr[i];
				}	
			}
			
		}
		b[n-1] = arr[n-1];
		for(int i=0;i<b.length;i++) {
			if(b[i] != 0)
			{	arr[count] = b[i];
				count++;
			}
		}
		return count;
	}

}
