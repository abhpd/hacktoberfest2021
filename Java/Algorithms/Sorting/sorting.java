//DIFFERENT ALGORITHMS FOR SORTING TECHNIQUES
//Date: 26/9/2021 
import java.util.Scanner;
class sorting
{
    int a[] = new int[10];
    Scanner sc = new Scanner(System.in);

    void create()
    {
     int n;
     System.out.println("Enter the length of array: ");//To input the length of array
     n = sc.nextInt();
     System.out.println("Enter the elements of the array: ");
     for(int i=0;i<n;i++)
     {
         a[i]=sc.nextInt();
     }
     System.out.println("");
     }

     void bubble_sort()
     {
         int temp;
         for(int i=0;i<a.length;i++)
         {
             for(int j=0;j<a.length-1;j++)
             {
                 if(a[j]>a[j+1])
                 {
                     temp=a[j];     //Swapping of values
                     a[j]=a[j+1];
                     a[j+1]=temp;
                 }
             }
         }
     }

     void display1()
     {
         System.out.println("The sorted list by binary sort is: "); //To display the sorted list
         for(int i=0;i<a.length;i++)
         {
             System.out.println(a[i]);
         }
         System.out.println(" ");
     }

    void selection_sort()
    {
        int low=0;
        int high=a.length-1;
        int temp, index;
        for(int i=0;i<=high;i++)
        {
            index=i;
            for(int j=i+1;j<=high;j++)
            {
                if(a[j]<a[index])
                {
                    index=j;
                }
                temp=a[i];
                a[i]=a[index];
                a[index]=temp;
            }
        }
    }

    void display2()
    {
        System.out.println("The sorted list by selection sort is: ");
        for(int i=0;i<a.length;i++)
        {
            System.out.println(a[i]);
        }
        System.out.println(" ");
    }

    void insertion_sort()
    {
        int temp, j;
        for(int i=1;i<a.length;i++)
        {
          temp=a[i];
          j=i;
          while(j>0&&a[j-1]>temp)
          {
              a[j]=a[j-1];
              j=j-1;
          }
          a[j]=temp;
        }
    }

    void display3()
    {
        System.out.println("The sorted list by insertion sort is: ");
        for(int i=0;i<a.length;i++)
        {
            System.out.println(a[i]);
        }
        System.out.println(" ");
    }

    void quick_sort()
    {
        int low = 0;
        int high = a.length-1;
        int pivot = a[(low+high)/2];
        while(low<=high)
        {
            while (a[low] < pivot)
            {
                low++;
            }
            while (a[high] > pivot)
            {
                high--;
            }
            if (low <= high)
            {
                int temp = a[low];
                a[low] = a[high];
                a[high] = temp;
                low++;
                high--;
            }
        }
    }

    void display4()
    {
        System.out.println("The sorted list by quick sort is: ");
        for(int i=0;i<a.length;i++)
        {
            System.out.println(a[i]);
        }
    }
}

public class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        sorting obj = new sorting();
        obj.create();
        obj.bubble_sort();
        obj.display1();
        obj.selection_sort();
        obj.display2();
        obj.insertion_sort();
        obj.display3();
        obj.quick_sort();
        obj.display4();
    }
}
