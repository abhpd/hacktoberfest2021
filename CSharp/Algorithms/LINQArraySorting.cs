using System;
using System.Linq;

public class LINQArraySorting
{
	public static void Main()
	{
		Console.WriteLine("-----------SORTING STRINGS USING LINQ WITH C#-------------");
		
		try{
			Console.Write("Enter the number of strings to sort: ");
			int numOfStrings = Convert.ToInt32(Console.ReadLine());
			
			string[] words = new string[numOfStrings];
			
			for(int i=0; i<numOfStrings; i++){
				Console.WriteLine("Enter String #"+i+": ");
				words[i] = Console.ReadLine();
			}
			
			var sortedArray = from word in words orderby word select word;
			
			Console.WriteLine("\nSorted List of Strings:");
			foreach(string str in sortedArray){
				Console.Write(str+" ");
			}
			
			Console.WriteLine("\n-------------------------------------------------------");
		}catch(Exception){
			
		}
	}
}
