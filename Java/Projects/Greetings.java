
import java.util.Scanner;

public class Greetings {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("What's your name?\n");
		String name = scanner.next();
		boolean more = true;
		
		while(more) {
			String greeting = getGreeting(name);
			System.out.println("\n" + greeting);
			System.out.println("\nMore greetings? (y/n)\n");
			
			if (!scanner.next().equals("y")) more = false;
		}
		
		
		scanner.close();
	}
	
	private static String getGreeting(String name) {
		int random = (int)(Math.random() * 10);
		
		switch (random) {
			case 0: return "Hi " + name;
			case 1: return "Hello " + name;
			case 2: return "Huhu " + name;
			case 3: return "What's up " + name + "?";
			case 4: return "How's your day " + name + "?";
			case 5: return "How are you " + name + "?";
			case 6: return "How is it going " + name + "?";
			case 7: return "Good to see you " + name;
			case 8: return "How do you do " + name + "?";
			case 9: return "Howdy " + name + "!";
			default: return "Whazzup " + name + "?";
		}
	}

}
