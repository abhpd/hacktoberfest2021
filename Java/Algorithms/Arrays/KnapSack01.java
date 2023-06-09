package AmazonPractice.DP;

public class KnapSack01 {
    public static void main(String args[]){
        int val[] = {60,100,120};
        int wt[] = {10,20,30};
        int W = 50;
        int answer = solveKnapsack(val,wt,W,val.length);
        System.out.println(answer);
    }
    
    public static int solveKnapsack(int v[], int wt[], int W, int n){
        int k[][] = new int[n+1][W+1];

        for(int i=0;i<=n;i++){
            for(int w=0;w<=W;w++){
                if(i==0 || w==0) k[i][w] = 0;
                else if(wt[i-1]<=w){
                    k[i][w] = Math.max(k[i-1][w],
                                        v[i-1]+k[i-1][w-wt[i-1]]);
                }
                else k[i][w] = k[i-1][w];
            }
        }
        return k[n][W];
    }
}