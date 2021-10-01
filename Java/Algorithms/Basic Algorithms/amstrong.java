public class amstrong {
    static boolean isArmstrong(int number){
        boolean amstrong = false;
        int n = 0;
        int num = number, digit = 0;

        double t= 0;

        while (num > 0){
            num = num / 10;
            n+=1;
        }
        num = number;
        while(num > 0) {
            digit = num % 10;
            t = t + Math.pow(digit, n);
            num =num / 10;
        }
        long total = Math.round(t);
        if(number == total){
            amstrong = true;
        }

        return amstrong;
    }

    public static void main(String[] args) {
        System.out.println(isArmstrong(153));
    }
}
