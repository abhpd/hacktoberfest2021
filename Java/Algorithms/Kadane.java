import java.io.*;

class Kadane {
    
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim());
		while(t-->0){
		    int n = Integer.parseInt(br.readLine().trim());
		    int arr[] = new int[n];
		    String inputLine[] = br.readLine().trim().split(" ");
		  
		    for(int i=0; i<n; i++){
		        arr[i] = Integer.parseInt(inputLine[i]);
		    }
		    System.out.println(maxSubarraySum(arr,n));
		}
  }
    
  public static int maxSubarraySum(int arr[], int n){
        
        int msum=0;
        int csum=0;
        
        for(int i=0;i<n;i++){
            csum+=arr[i];
            
            if(csum>msum){
                msum=csum;
            }
            
            if(csum<0){
                csum=0;
            }
        }
        return msum;
        
    }
}
