import java.util.Scanner;

public class DigitPattern_7 {
       public static void main(String[] args) {
           Scanner sc = new Scanner(System.in);

           int height, width;

           System.out.print("\nEnter the height of 7 : ");
           height = sc.nextInt();
           width = height+2;

           System.out.println();
           for(int i = 1; i <= height; i++){
               for(int j = 1; j <= width; j++){
                   if(i == 1){
                       System.out.print("*");
                   }
                   else if(j == width-i+2){
                       System.out.print("*");
                   }
                   else{
                       System.out.print(" ");
                   }
               }
               System.out.println();
           }

           System.out.println("\n\n");
       }   
}