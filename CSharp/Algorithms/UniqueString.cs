using System;
 
namespace UniqueString
{
    // Implements an algorithm to determine if a string has all unique characters.
    // Compares each character to every other character without using an additional data structure
    // The algorithm is case-sensitive, since A character != a
    public static class UniqueString
    { 
        public static bool IsUnique(string s)
        {
            string temp1 = "";
            string temp2 = "";
 
            // Loop through the characters of the string
            for (int i = 0; i < s.Length; i++)
            {
                // Gets the next character
                temp1 = s.Substring(i, 1);
                for (int k = 0; k < s.Length; k++)
                {
                    temp2 = s.Substring(k, 1);
					
                // Check if another instance of the character exists in the whole string
                if ((temp1 == temp2) && (i != k))
                        return false;
                }
            }
            return true;
        }
		
        // Driver Code
        public static void Main(string[] args)
        {
            Console.WriteLine(IsUnique("Samuel")); // True
            Console.WriteLine(IsUnique("Alan")); // True
            Console.WriteLine(IsUnique("alan")); // False
        }
    }
}
