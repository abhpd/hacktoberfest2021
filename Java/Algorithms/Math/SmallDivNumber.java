public class SmallDivNumber {
    public static void main(String[] args) {
        System.out.println(getSmallestDivNum(3));
    }

    public static long getSmallestDivNum(int n){
        long a = 1;
        for(int b=2;b<=n;b++){
            a = (a*b)/getGcd(a,b);
        }
        return a;
    }

    public static long getGcd(long a,long b){
        if(a==0){
            return b;
        }else{
            return getGcd(b%a,a);
        }
    }
}
