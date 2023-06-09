import java.util.Scanner;

public class DigitPattern_3 {
       public static void main(String[] args) {
           Scanner sc = new Scanner(System.in);

           int height;
           System.out.print("\nEnter the Height of 3 : ");
           height = sc.nextInt();

           int width = height-1;

           System.out.println();
           for(int i = 1; i <= height; i++){
               for(int j = 1; j <= width; j++){
                   if( (i == 1 && j != width) || (i == height/2+1  && j != width) || (i == height && j != width ) 
                       || (j == width && i != 1 && i != height/2+1 && i != height) ){
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