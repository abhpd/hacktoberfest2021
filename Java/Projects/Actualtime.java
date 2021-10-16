// Import what we need.
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

// Create class.
public class Actualtime {
    // Create main method.
    public static void main(String[] args) {
        // Set the date/time format we want.
        DateTimeFormatter timeformat = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        // Create a Scanner object
        Scanner scan = new Scanner(System.in); 
        //asking to the user if he wants to know the time
        System.out.println("Do you want to know what time is it?" + "\n" + "yes" +"\n" + "no")
        //reading the input
        String answer = scan.nextLine();
        //adding a control so if the user say yes we print the time.
        if(answer=="yes"){
        // Print the result.
        System.out.println(timeformat.format(now));
        }
      
    }
}
// By Fonta22
