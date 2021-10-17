package utilities;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ReadFile {

	public static void main(String[] args) throws FileNotFoundException   {
		// TODO Auto-generated method stub
		File file = new File("/Users/gafv/eclipse-workspace/doc/samplefile.txt");
		Scanner scan = new Scanner(file); 
		
		while(scan.hasNextLine()) {
			String line = scan.nextLine();
			String names[] = line.split(",");
			
			String email = names[0].trim();
			String name = names[1];
			String subject = names[2]; 
			String messageBody = names[3];
			
			/*System.out.println(email);
			System.out.println(name);
			System.out.println(subject);
			System.out.println(messageBody);*/
			
			SendMail m1 = new SendMail();
			m1.getData(email, subject, messageBody);
			m1.Send();
			m1.Store();
			m1.DisplayData();
		}
	}

}
