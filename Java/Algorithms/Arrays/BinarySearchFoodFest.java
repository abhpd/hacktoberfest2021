import java.io.*; // for handling input/output
import java.util.*; // contains Collections framework


class Main {

    /*
        4 10
        1 2 3 4

        Sol = 6
        
        6/1 = 6
        6/2 = 3
        6/3 = 2
        6/4 = 1
        --------
             12

        Sol = 5
        5/1 = 5
        5/2 = 2
        5/3 = 1
        5/4 = 1
        --------
              9

        p = 10
        [1,2,3,4]
        low = 1, high = min*p = 10, 1<=sol<=10, p = 10dishes
        while(low <= high)
        (1mins, 10mins, 5mins), dishes_mid=5+2+1+1=9, low = mid + 1 = 6mins
        (6mins, 10mins, 8mins), dishes_mid=8+4+2+2=16, sol = 8mins, high = mid - 1 = 7mins
        (6mins, 7mins, 6mins), dishes_mid=6+3+2+1=12, sol = 6mins, high = mid - 1 = 6mins
        (6mins, 6mins, 6mins), dishes_mid=6+3+2+1=12, sol = 6mins, high = mid - 1 = 5mins
        (6mins, 5mins) low > high!

    */


    public static long calculateDishes(long arr[], int n, long mid){
        long dishes_mid = 0;
        for(int i = 0; i < n; i++){
            dishes_mid += (mid / arr[i]);
        }
        return dishes_mid;
    }

	public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long p = sc.nextLong();
        long arr[] = new long[n];
        long low = 1, high = Long.MAX_VALUE;
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextLong();
            if(high > arr[i]){
                high = arr[i]; //We will get min time of all people
            }
        }
        high = high * p; //Max amount of time taken.
        long sol = high;
        while(low <= high){
            long mid = low + (high - low) / 2;
            long dishes_mid = calculateDishes(arr, n, mid);
            if(dishes_mid < p){
                low = mid + 1;
            }
            else{
                sol = mid;
                high = mid - 1;
            }
        }
        System.out.println(sol);

	}
}
