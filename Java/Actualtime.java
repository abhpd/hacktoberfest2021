package hacktoberfest2020.Java;

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
        // Print the result.
        System.out.println(timeformat.format(now));
    }
}
// By Fonta22
