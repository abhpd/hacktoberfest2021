//Java Program to demonstrate the way of passing an anonymous array  
//to method.  
public class TestAnonymousArray{  
    //creating a method which receives an array as a parameter  
    static void printArray(int arr[]){  
    for(int i=0;i<arr.length;i++)  
    System.out.println(arr[i]);  
    }  
      
    public static void main(String args[]){  
    printArray(new int[]{10,22,44,66});//passing anonymous array to method  
    }}  