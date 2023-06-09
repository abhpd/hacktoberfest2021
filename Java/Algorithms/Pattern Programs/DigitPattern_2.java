import java.util.Scanner;

public class DigitPattern_2 {
      public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);

          int height;
          System.out.print("\nEnter the Height of 2 : ");
          height = sc.nextInt();

          int width = height;
          int mid = height/2 +1;
          
          System.out.println();
          for(int i = 1; i <= height; i++){
            for(int j = 1; j <= width; j++){
                if(i == 1 || i == mid || i == height){
                    System.out.print("*");
                }else if((i <= mid && j == width) || (i >= mid && j == 1)){
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