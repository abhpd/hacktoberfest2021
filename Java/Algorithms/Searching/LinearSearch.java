import java.util.*;
class LinearSearch
{
   public static void main(String args[])
   {
      int c, num, item, array[];
      
      Scanner sc = new Scanner(System.in);
      System.out.println("Enter number of elements:");
      num = sc.nextInt(); 
      //Creating array to store the all the numbers
      array = new int[num]; 
      System.out.println("Enter " + num + " integers");
      //Loop to store each numbers in array
      for (c = 0; c < num; c++)
        array[c] = input.nextInt();

      System.out.println("Enter the search value:");
      item = sc.nextInt();

      for (c = 0; c < num; c++)
      {
         if (array[c] == item) 
         {
           System.out.println(item+" is present at location "+(c+1));
           break;
         }
      }
      if (c == num)
        System.out.println(item + " doesn't exist in array.");
   }
}
