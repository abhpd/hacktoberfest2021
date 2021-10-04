
package array;


public class test { 
	   	static int res(int arr[]) {
	   		int sum=0,max=0;
	   		for(int i=0;i<arr.length;i++) {
	   			sum += arr[i];
	   			sum = Math.max(sum, arr[i]);
	   			max = Math.max(max, sum);
	   		}
	   		return max;
	   	}
	     public static void main(String []args){
	    	 int arr[] = {-2,1,3,-2,5,-8};
	    	 System.out.print("Max sum sub arry is: ");
	    	 int max=0;
	    	 for(int i=0;i<arr.length;i++) {
	    		 int sum=0;
	    		 for(int j=i;j<arr.length;j++) {
	    			 sum+=arr[j];
	    			 max = Math.max(max, sum);
	    		 }
	    	 }
	    	System.out.println(max);
	    	System.out.println("Using Kadene algo: "+res(arr));
	     }
	     
	}
