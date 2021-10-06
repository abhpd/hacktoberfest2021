public class SumOfNnatural {
    public static void main(String[] args) {
        System.out.println(sumofnum(5));
        System.out.println(sumofNum(5));
    }


    //normal way --> O(n)
    static int sumofnum(int n){
        int sum = 0;
        for(int i=1;i<=n;i++){
            sum+=i;
        }
        return sum;

    }

    //efficient way --> O(1)

    static int sumofNum(int n){
        return n*(n+1)/2;
    }

}

// #1+2+3+4+5