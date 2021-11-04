import java.util.Scanner;

public class Basics_Calculator {

	public static void main(String[] args) {
		int opc,num1,num2;
		boolean exit=false;
		do {
			try {
			Scanner sc = new Scanner(System.in);
			System.out.println("*****Calculator Hacktoberfest 2021*****");
			System.out.println("1º Plus");
			System.out.println("2º Minus");
			System.out.println("3º Times");
			System.out.println("4º Divided by");
			System.out.println("*) Exit");
			System.out.println("*****************************************");
			System.out.print("Select option: \t");
			opc=sc.nextInt();
			
				switch (opc) {
				case 1:
					System.out.println("Tell me the first number");
					num1=sc.nextInt();
					System.out.println("Tell me the second number");
					num2=sc.nextInt();
					int sum=num1+num2;
					System.out.println("Is : "+sum);
					break;
				case 2:
					System.out.println("Tell me the first number");
					num1=sc.nextInt();
					System.out.println("Tell me the second number");
					num2=sc.nextInt();
					int rest=num1-num2;
					System.out.println("Is : "+rest);
					break;
				case 3:
					System.out.println("Tell me the first number");
					num1=sc.nextInt();
					System.out.println("Tell me the second number");
					num2=sc.nextInt();
					int mult=num1*num2;
					System.out.println("Is : "+mult);
					break;
				case 4:
					System.out.println("Tell me the first number");
					num1=sc.nextInt();
					System.out.println("Tell me the second number");
					num2=sc.nextInt();
					int div=num1/num2;
					int mod=num1%num2;
					System.out.println("Is "+div+" and the mood is "+mod);
					break;

				default:
					System.out.println("By,Have a great time");
					exit=true;
					break;
				}
			} catch (Exception e) {
				// TODO: handle exception
				System.out.println("By,Have a great time");
				exit=true;
			}
					
		} while (exit==false);
		
	}

}
