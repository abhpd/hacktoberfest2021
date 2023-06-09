import java.util.*;  
import java.io.*;     

class Examination_map {

    public static void main(String [] args) throws Exception {
      
        /* Read input and save as entries in  HashMap */                  

        Scanner in = new Scanner(System.in);
                System.out.print("Enter no of candidates: ");
                int n = in.nextInt();   // Get the number of entries

        HashMap<String,String> map = new HashMap<>();    // Create the hashMap
       
        System.out.println("\n Input Entries to the List \n");

            for (int i = n-1; i >= 0;  i -= 1) {   // Loop to compare no of candidates and 1, then decreases no of candidates by 1
               
                Scanner logn = new Scanner(System.in);         // Get names as variable name'name' to add to hashMap
                    System.out.println("Name: ");    
                    String name = logn.next();                  
                                                               
                Scanner logp = new Scanner(System.in);          // Get index numbers as variable name'id' to add to hashMap
                    System.out.println("Index Number: ");      
                    String id = logp.next();                
                
                map.put(id, name);   // put each name and id to the map (key-name, value-id) 
            }
   
        System.out.println("\n\tCandidate List\n");
        System.out.println("\tIndex No.    | Name    ");
        System.out.println("--------------------------------");

       
        for (Map.Entry<String,String> entry : map.entrySet())                       // Iterating over the hashMap's entry set using for loop
                System.out.println("\t"+entry.getValue() + "\t|\t" + entry.getKey()); // print each key-value pairs

                System.out.println("\n--------------------------------\n");

                System.out.println("\nEnter index number to get name");
                Scanner nw = new Scanner(System.in);    // Get a key element to find the relevent value
        
        String s;    // parameter to assign above key element (name)
        
        /* Read each query and check if its in the HashMap */
        while((s = nw.nextLine()) != null) {    
          
            if (map.containsKey(s)) {        // Check whether the particular key value 's' is being mapped into the hashMap
                System.out.println("\n"+s+" : "+(map.get(s)));     // Get the relevent value 
            } 
            else {
                System.out.println("Not found");
            }
        }
       
    }
}