

/*
Write a program to print letter K exactly as shown below -

##     @@
##    @@
##   @@
##  @@
##@@
## @@
##  @@
##   @@
##    @@

*/



import java.util.Scanner;

public class Letter_K{
    
  public static void main(String[] args){
      
    Scanner scan =new Scanner(System.in);
    System.out.println("Please specify the height of the alphabet greater than 0");
    
    int patternHeight = scan.nextInt();
    
    if(patternHeight<1){
        System.out.println("Please specify the height of the alphabet greater than 0");
    }
	else{
		printK(patternHeight);
	}
  }
  
  // main logic
  public static void printK(int n){
        // part 1 upper half
        for(int i = 0; i< n; i++){
            System.out.printf("##");
            for(int j =0; j<(n-i+1); j++){
                System.out.printf(" ");
            }
            System.out.printf("@@");
            System.out.println();
        }
        //part 2 middle pattern
        System.out.println("##@@");
		
		//part 3 lower half
        for(int i = 1; i<= n; i++){
            System.out.printf("##");
            for(int j =1; j<=i; j++){
                System.out.printf(" ");
            }
            System.out.printf("@@");
			System.out.println();
        }
	}
}