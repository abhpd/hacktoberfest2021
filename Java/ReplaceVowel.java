import java.util.Scanner;

public class ReplaceVowel {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        String string=scanner.nextLine();
        String newString="";
        for (int i=0;i<string.length();i++){
            char ch=string.charAt(i);
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
                newString+="*";
            }else{
                newString+=ch;
            }
        }
        System.out.println(newString);
    }

}
