import java.util.Scanner; 

class PyramidPattern {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter heigth of pyramid. ");
        int rows = sc.nextInt();
        int count = 1;


        for(int i = rows; i >= 1; i--) {      // loop for rows
            for(int j = i; j >= 1; j--) {     // loop for gap 
                System.out.print("  ");
            }
            
            for(int j = 1; j <= count; j++) {   //  loop for print numbers
                if(j > count/2) {
                    for(int k = j; k >= 1; k--) {  //loop for print decreasing number after middle of pyramid
                        System.out.print(k+" ");
                    }
                    break;                     // break after reached number 1 at last
                }
                else {
                    System.out.print(j+" ");
                }
                
            }
            count += 2;
            System.out.println();     // used for new line
        }
        
    }
    
}

