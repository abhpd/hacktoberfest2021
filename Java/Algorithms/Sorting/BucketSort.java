//srishti1302
import java.util.*;
 
public class Bucket
{
    static int[] sort(int[] sequence, int maxValue) 
    {
        // Bucket Sort
        int[] Bucket = new int[maxValue + 1];
        int[] sorted_sequence = new int[sequence.length];
 
        for (int i = 0; i < sequence.length; i++)
            Bucket[sequence[i]]++;
 
        int outPos = 0;
        for (int i = 0; i < Bucket.length; i++)
            for (int j = 0; j < Bucket[i]; j++)
                sorted_sequence[outPos++] = i;
 
        return sorted_sequence;
    }
 
    static void printSequence(int[] sorted_sequence) 
    {
        for (int i = 0; i < sorted_sequence.length; i++)
            System.out.print(sorted_sequence[i] + " ");
    }
 
    static int maxValue(int[] sequence) 
    {
        int maxValue = 0;
        for (int i = 0; i < sequence.length; i++)
            if (sequence[i] > maxValue)
                maxValue = sequence[i];
        return maxValue;
    }
 
    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Sorting numbers using BUCKET SORT");
        System.out.println("Enter the size:");
        int N = sc.nextInt();
        int[] sequence = new int[N];
 
        for (int i = 0; i < N; i++)
        {
            System.out.println("Enter the element"+(i+1));
            sequence[i] = sc.nextInt();
        }
 
        int maxValue = maxValue(sequence);
 
        System.out.println("\nOriginal Sequence: ");
        printSequence(sequence);
 
        System.out.println("\nSorted Sequence: ");
        printSequence(sort(sequence, maxValue));
    }
}
