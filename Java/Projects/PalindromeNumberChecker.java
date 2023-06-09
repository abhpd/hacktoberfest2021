import java.util.*;

public class PalindromNumberChecker{
public static void main(String[] args){
	int length;
	String number;
	String changed="";
	Scanner sc = new Scanner(System.in);
	System.out.println("enter number");
	number = sc.nextLine();
	length=number.length();
	for(int i=length-1;i>=0;i--){
		changed=changed+number.charAt(i);
	}
	if (number.equals(changed)){
			System.out.println("This is a palindrome number");
		}else{
			System.out.println("this is not a palindrome number");
		}
	
	
}
}