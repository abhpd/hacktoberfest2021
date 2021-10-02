import java.util.Scanner;

public class JosephusProblem {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		JosephusProblem p = new JosephusProblem();
		System.out.println("Enter numbers of people: ");
		int n = sc.nextInt();
		System.out.println("Enter k: ");
		int k = sc.nextInt();
		System.out.println("The safe place is: " + p.josephus(n, k));
		

		sc.close();
	}
	
	public int josephus(int n, int k) {
		if(n == 0)
			return 0;
		return (josephus(n-1, k)+k-1)%n+1;
	}

}
