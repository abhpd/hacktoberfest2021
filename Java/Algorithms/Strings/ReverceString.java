public class ReverceString {
    public static void main(String[] args) {
        String word = "Hacktoberfest2021";
        String reverce = "";
        for(int i=1 ; i < word.length() + 1 ; i++){      
            reverce +=  word.charAt(word.length() - i);
        }
        System.out.println(reverce);
    }
}