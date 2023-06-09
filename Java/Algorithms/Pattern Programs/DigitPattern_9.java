import java.util.Scanner;

public class DigitPattern_9 {
       public static void main(String[] args) {
           Scanner sc = new Scanner(System.in);

           int height, width;
           System.out.print("\nEnter the height of 9 : ");
           height = sc.nextInt();
           width = height;

           System.out.println();
           for(int i = 1; i <= height; i++){
               for(int j = 1; j <= width; j++){
                   if((i == 1) && (j != 1 && j != width)){
                       System.out.print("*");
                   }
                   else if((i > 1 && i < height/2+1) && (j == 1 || j == width)){
                       System.out.print("*");
                   }
                   else if((i == height/2+1) && (j != 1)){
                       System.out.print("*");
                   }
                   else if((i > height/2+1 && i < height) && (j == width)){
                       System.out.print("*");
                   }
                   else if((i == height) && (j != width)){
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