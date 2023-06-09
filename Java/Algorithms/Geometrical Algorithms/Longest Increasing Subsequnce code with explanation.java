
import java.io.*;
import java.util.*;
// This code is to find longest increasing subsequence, which is an standard problem of DP
import java.io.*;
import java.util.*;
// This code is to find longest increasing subsequence, which is an standard problem of DP
public class LIS {
	// method 1- Time complexity is O(n2) , space complexity is sc(n)
	    public static void main(String[] args) throws Exception {
	        Scanner sc=new Scanner(System.in); // class to take inputs
	        int n=sc.nextInt(); // no of elements
	        int[] a=new int[n];
	        for(int i=0;i<n;i++){
	            a[i]=sc.nextInt(); // take inputs for array elements
	        }
	        // dp array to store lis for every element
	        int[] dp=new int[n];
	        dp[0]=1; 
	        int ans=1; // min ans would be 1
	        for(int i=1;i<n;i++){
	            int lolis=1; // min size of lis would be 1 
	            for(int j=0;j<i;j++){
	                if(a[i]>=a[j]){ // if a[i] greater than that means it can be added to the lis
	                    lolis=Math.max(lolis,dp[j]+1);
	                }
	            }
	            
	            dp[i]=lolis;
	            ans=Math.max(ans,dp[i]);
	        }
	        System.out.print(ans);
	        
	    }
	 // method 2- Time complexity is O(nlogn) , space complexity is sc(n) 
	        public int lengthOfLIS(int[] nums) {
	            ArrayList<Integer> a=new ArrayList<>();
	            a.add(nums[0]);
	            for(int i=1;i<nums.length;i++){
	                 int le=a.get(a.size()-1);
	                 if(le<nums[i]){ a.add(nums[i]);}
	                else{
	                    int ind=binary_search(a,nums[i]);
	                    a.set(ind,nums[i]);
	                }
	            }
	            return a.size();
	        }
	        int binary_search(ArrayList<Integer> a,int ele){
	            Collections.sort(a);
	            int l=0,h=a.size();
	            while(l<=h){
	                int mid=l+(h-l)/2 ;
	                if(a.get(mid)==ele){return mid;}
	                else if(a.get(mid)>ele){h=mid-1;}
	                else l=mid+1;
	            }
	            return l;
	        }
	    
	    

	
}
