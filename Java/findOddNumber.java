class FindOddNumber {
   public static void main(String args[]) {
	int n = 100;
	System.out.print("Odd Numbers from 1 to "+n+" are: ");
	for (int i = 1; i <= n; i++) {
	   if (i % 2 != 0) {
		System.out.print(i + " ");
	     }
	   }
   }
}