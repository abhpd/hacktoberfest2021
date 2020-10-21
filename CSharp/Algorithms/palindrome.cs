using System;

namespace Algorithms.Polindrome
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var str1 = "100001";
            Console.WriteLine($"Is {str1} palindrome = {IsPalindrome(str1)}.");

            var str2 = "abcde";
            Console.WriteLine($"Is {str2} palindrome = {IsPalindrome(str2)}.");

            var str3 = "lol";
            Console.WriteLine($"Is {str3} palindrome = {IsPalindrome(str3)}.");
        }

        public static bool IsPalindrome(string str)
        {
            var length = str.Length;
            var halfLength = length / 2;

            for (int i = 0; i < halfLength; i++)
                if (str[i] != str[length - i - 1])
                    return false;

            return true;
        }
    }
}
