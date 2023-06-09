package CyclicSort;
public class cyclicsort{
	/**
	 * cyclic sort Agorithm
	 *
	 *Input values of orignal array should be 1<=value<=N
	 *Where N=size of array
	 */
	public static void main(String[] args){
	      int[] nums={3,4,2,1,5,7,6};
	      sortcyclic(nums);
	      for(int i=0;i<nums.length;i++){
	      	   System.out.println(nums[i]); 
	      }
	}
	/**
	 * Cyclic sort algorithms places each element at its right position
	 *  eg- postion of 1 in sorted array is 0
	 *  position of 7 is 6
	 */
	public static void sortcyclic(int[] arr{
	            int i=0;
	     	    while(i<arr.length){
		    int correct=arr[i]-1;
		    if(arr[i]!=arr[correct]){
			swap(arr,i,correct);		
		     }
		}	
	}
	public static void swap(int[] arr,int i,int j){
	         int temp=arr[i];
		 arr[i]=arr[j];
		 arr[j]=temp;
	}
}
