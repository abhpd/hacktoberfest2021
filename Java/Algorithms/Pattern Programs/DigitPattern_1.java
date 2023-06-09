import java.util.Scanner;

public class DigitPattern_1 {
       public static void main(String[] args) {
           Scanner sc = new Scanner(System.in);

           int height, width;
           System.out.print("\nEnter the Height of 1 : ");
           height = sc.nextInt();
           width = height - 2;

           System.out.println();
           for(int i = 1; i <= height; i++){
               for(int j = 1; j <= width; j++){
                   if(j == width/2+1){
                       System.out.print("*");
                   }else if(i < height/2+1 && j <= width/2+1 && (i + j == height/2+1)){
                       System.out.print("*");
                   }else if(i == height){
                       System.out.print("*");
                   }else{
                       System.out.print(" ");
                   }
               }
               System.out.println();
           }
           

           System.out.println("\n\n");
       }    
}