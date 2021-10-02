import java.util.*;
public class Prg{
    public static void main(String[] args) {
     
        Scanner sc = new Scanner(System.in);

//    Taking two string as a input
  
       String first = sc.next();
       
       String second = sc.next();

       int a[] = new int[26];
       int b[] = new int[26];

    //   Storing thier ascii index value in array

       for(int i =0; i<first.length(); i++){
           int index = (int) first.charAt(i);
           a[index-97]++;
       }
       for (int i =0; i<second.length(); i++){
           int index = (int) second.charAt(i);
           b[index-97]++;
       }

    //    for checking their index for frequency of aplhabet

    boolean is = true;
    for(int i =0; i<26; i++){
        if(a[i] != b[i]){
            is = false;
            break;
        }
    }
     
     if(is == true){
         System.out.println("strings are Anagram..");
     }else{
         System.out.println("Strings sre not Anagram..");
     }

    }
}
