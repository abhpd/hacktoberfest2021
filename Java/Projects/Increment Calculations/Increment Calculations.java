import java.util.*;
public class IncrementCalculation{
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the salary");
        int salary = sc.nextInt();
        System.out.println("Enter the Performance appraisal rating");
        double rating = sc.nextDouble();
        int increment =0;
        
        
        if(salary<=0 || rating<1 || rating>5)
        {
          System.out.println("Invalid Input");  
        }
        else{
            if(rating>=1 && rating<=3)
            {
                increment = 10;
            }
            else if(rating>=3.1  && rating<=4)
            {
                increment = 25;
            }
            else if(rating>=4.1 && rating<=5)
            {
                increment = 30;
            }
            
            System.out.println(salary+(salary*increment)/100);
        }
    }
}