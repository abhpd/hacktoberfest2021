class Prime {
    static int i = 2;
    public static boolean isPrime(int n){
        if (n == 0 || n == 1)
            return false;   
        if (n == i)
            return true;
        if (n % i == 0)
            return false;
        i++;
        return isPrime(n);
    }
    public static void main(String[] args){
        if (isPrime(35))
            System.out.println("true");
        else
            System.out.println("false");
    }
}