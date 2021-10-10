import java.util.Scanner;

public class DigitPattern_4 {
       public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);   
        int height, width;

        System.out.print("\nEnter the height of 4 : ");
        height = sc.nextInt();
        width = height;
        int mid = height - (height/2)+2;

        System.out.println();
        for(int i = 1; i <= height; i++){
            for(int j = 1; j <= width; j++){
                 if(i < mid){
                     if(j == height-i-1 || j == height-2){
                         System.out.print("*");
                     }else{
                         System.out.print(" ");
                     }
                 }    
                else{
                    if(i == mid || j == height-2){
                        System.out.print("*");
                    }else{
                        System.out.print(" ");
                    }
               
                }
            
            }
            System.out.println();
                    
        }

        System.out.println("\n\n");
            
       }    
}