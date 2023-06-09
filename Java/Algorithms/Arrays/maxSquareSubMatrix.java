package AmazonPractice.DP;

public class maxSquareSubMatrix{
    public static void main(String args[]){
        boolean arr[][] = {{false,true,false,false},
                            {true,true,true,true},
                            {false,true,true,false}};
        
        System.out.println(calc(arr));
    }

    static int calc(boolean arr[][]){
        int cache[][] = new int[arr.length][arr[0].length];
        int max = 0;

        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr[0].length;j++){
                if(i==0 || j==0) cache[i][j] = arr[i][j] ? 1:0;
                else if(arr[i][j]){
                    cache[i][j] = Math.min(Math.min(cache[i-1][j],cache[i][j-1]),cache[i-1][j-1]+1);
                }
                if(cache[i][j]>max) max=cache[i][j];
            }
        }
        return max;
    }
}
