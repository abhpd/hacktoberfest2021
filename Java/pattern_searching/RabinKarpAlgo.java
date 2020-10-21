import java.util.Scanner;

/**
 *
 * This is Rabin-Karp Algorithm used in pattern searching in String.
 * This algorithm used hash function to find the given pattern in the Input String.
 *
 * code by Jetty53
 */

public class RabinKarpAlgo {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

//        Example text = "CCACCAAEDBA";
//        Example pattern = "DBA";

        System.out.println("Enter the input String: ");
        String text = sc.nextLine();

        System.out.println("Enter the pattern String: ");
        String pattern = sc.nextLine();

        int prime = 101;

        //The pattern length cannot be more than the length of the input string.
        if(pattern.length() <= text.length()){
            rabinKarp(text, pattern, prime);
        }else{
            System.out.println("Pattern string cannot be longer than the main string.");
        }

    }

    private static void rabinKarp(String text, String pattern, int prime) {

        int patLen = pattern.length();
        int textLen = text.length();
        int pow = 1;
        int j;
        int flag = 0;
        final int chars = 256;

        //this is the hash value of the pattern string initialized with 0
        long hashPat = 0;

        //this is the hash value of the main text initialized with 0
        long hashTxt = 0;

        for (int i = 0; i <= patLen - 1; i++) {

            //this is the calculation of the hash value of the pattern text
            hashPat = (chars * hashPat + pattern.charAt(i)) % prime;

            //this is the calculation of the hash value of first block of the main text
            //[CCA]CCAAEDBA
            //so this only the calculation of the hash value of CCA
            hashTxt = (chars * hashTxt + text.charAt(i)) % prime;

        }

        //According to the hash function pow is (chars ^ (patLen - 1)) % prime
        for (int i = 0; i < patLen - 1; i++) {
            pow = (pow * chars) % prime;
        }

        //Sliding the block one by one over the main text and check the hash value with the pattern
        for (int i = 0; i <= textLen - patLen; i++) {

            //If Pattern hash value and Main Text Block hash value gets equal, then we have to check character by character
            if (hashPat == hashTxt) {

                for (j = 0; j <= patLen - 1; j++) {
                    if (pattern.charAt(j) != text.charAt(i + j)) {
                        break;
                    }
                }

                if (j == patLen){
                    flag = 1;
                    System.out.println("The pattern is present at "+i+" index.");
                }
            }

            //Calculating the hash value of the next block in the main string within O(1) time, using rolling hash function
            if (i <= (textLen - patLen) - 1) {

                hashTxt = (((hashTxt - ((long) text.charAt(i) * pow)) * chars) + (long) text.charAt(i + patLen)) % prime;
                hashTxt = (hashTxt < 0) ? hashTxt + prime : hashTxt;

            }
        }

        //If the given pattern does not exist in the input String
        if (flag == 0){

            System.out.println("This pattern is not present in the input string.");

        }

    }
}

