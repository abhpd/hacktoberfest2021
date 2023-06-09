import java.util.ArrayList;     
import java.util.PriorityQueue;      
import java.util.Scanner;        
import java.util.List;                            
import java.util.Comparator;         

class Examination {      // Class to get inputs                   
    private int id;            // Declare two instance variables as id and and gpa                       
    private float gpa;                   
                            
    public Examination(int id, float gpa) {
        super();            // Call parent class constructor to set index no and gpa of the student       
        this.id = id;       // instantiating variables
        this.gpa = gpa;    
    }

    public int getId() {    // To return the index no 
        return id;
    }
   
    public float getGpa() {  // To return GPA
        return gpa;
    }
}


class Priorities {      // Class to assign priorities

    // Implement a method to process all the input entries and return the entries yet to be served in the priority list
    public List < Examination > getResult(List < String > entries) {  

        // Assign a queue as 'result_queue'
        PriorityQueue < Examination > result_queue = new PriorityQueue(Comparator.comparing(Examination::getGpa).reversed().thenComparing(Examination::getId)); 
                                                                       // The students having highest GPA is served first. 
                                                                       // If any students having same GPA, served by index number ascending order.
       
        List < Examination > result_set = new ArrayList < Examination > ();  // Assign a list 'result_set' to return entries at the end

        for (String e: entries) {        // loop through the 'e' entries in list 'entries'
            Scanner sc =new Scanner(e);  // To get total number of entries in the list
           
                String name = sc.next();            
                float gpa = sc.nextFloat();   
                int id = sc.nextInt();

                Examination examination = new Examination(id, gpa);
                result_queue.add(examination);    // add 'id' and 'gpa' values to the queue
            
        }

        Examination first = result_queue.poll(); // To remove and return entries one by one from the queue
        
        if (first == null) {                     // If no more entries in the list return the result set    
            return result_set;   
        } 
        else {
            while (first != null) {             // If there is another entry in the list,,

                result_set.add(first);          // add it to the list,,
                first = result_queue.poll();    // Remove and return added entry from the queue
            }
            return result_set;
        }

    }
}


            
public class Examination_queue {     // Main class

    private final static Scanner scan = new Scanner(System.in);
    private final static Priorities priorities = new Priorities();

    public static void main(String[] args) {


        System.out.println("\n Enter number of entries");
        int totalEntries = Integer.parseInt(scan.nextLine());   // To get number of entries in the queue
        
        System.out.println("\n Input entries");  
        System.out.println("\n  Name | GPA | Index No");

        List<String> entries = new ArrayList<>();   //  Assign an array list as 'entries'

        for (int i = totalEntries-1; i >= 0;  i -= 1) {
            String name = scan.nextLine();
            entries.add(name);      // Add entered names to the array list 
        }
        
        List<Examination> result_set = priorities.getResult(entries);      
         System.out.println("\n --Result Sheet--\n"); 

        if (result_set.isEmpty()) {  // Check if the queue is empty
            System.out.println("No entries in the list");
        } 

        else {
            System.out.println("Index No | GPA");
            for (Examination sheet:result_set) {                         // iterate through each entry withing number of inputs
                System.out.println(sheet.getId()+" | "+sheet.getGpa());  // Print the index number and GPA of each candidate
            }
        }
    }
}
