// FIND SMALLEST LETTER GREATER THAN TARGET.

/*Given a characters array letters that is sorted in non-decreasing order and a character target,
return the smallest character in the array that is larger than target. */

public class BinarySearch {
    public static void main(String[] args) {
        char[] letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
        char target = 'j';
        System.out.println(findChar(letters, target));
    }
    static char findChar(char[] letters, char target)
    {
        int start =  0;
        int end = (letters.length - 1);
        if(target >= letters[end] || target <= letters[start])
        {
            return letters[start];
        }
        while(start <= end)
        {
            int mid = start + (end - start) /2;
            if( target == letters[mid])
            {
                return letters[mid+1];
            }
            else if(target < letters[mid])
            {
                end = (char) (mid - 1);
            }
            else
            {
                start =  (char) (mid + 1);
            }
        }
        return letters[start];
    }
}