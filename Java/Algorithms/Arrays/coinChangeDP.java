import java.util.Arrays;

public class coinChangeDP{
    public static void main(String args[]){
        int arr[] = {1,2,3};
        int m = arr.length;
        int n = 4;
        System.out.println(count(arr,m,n));
    }

    static int count(int arr[], int m, int n){
        int table[] = new int[n+1];
        Arrays.fill(table, 0);
        table[0]=1;

        for(int i=0;i<m;i++){
            for(int j=arr[i];j<=n;j++){
                table[j] = table[j] + table[j-arr[i]];
            }
        }

        return table[n];
    }
}
