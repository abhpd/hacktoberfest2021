import java.util.Scanner;

public class KbcProgram {
    static void myBot(String a,String b[],int i){
        a=b[i];
    }

    public static void main(String[]arg){
      String[] quest =new String[6];
        String[] a =new String[6];
        String[] b =new String[6];
        String[] c =new String[6];
//        String d[] =new String[5];
//    **********************************************************************
        // Questions
        quest[1]="Who is lazy, funny, and sly in almost everything he/she does?";
        quest[2]="Who is Know as Fire Brigade ?";
        quest[3]="Who is Garba Queen ?";
        quest[4]="What is Children Group in Society ?";
        quest[5]="Who is known as Great Foodie ?";
//    **********************************************************************
      // Options                            correct
         a[1]="Jetha";b[1]="Mehta";         c[1]="Jetha";
         a[2]="Bhide";b[2]="Mehta";         c[2]="Mehta";
         a[3]="Daya";b[3]="Babita";          c[3]="Daya";
         a[4]="Gopu Sena";b[4]="Tapu Sena";  c[4]="Tapu Sena";
         a[5]="Haathi";b[5]="Jetha";         c[5]="Haathi";
//    **********************************************************************
      // FUNCTION
        int score=0;
        Scanner sc=  new Scanner(System.in);
        for(int i=1;i< quest.length;i++){
            System.out.println(i +" " +quest[i]);
            System.out.println(a[i]+"        "+b[i]);
            System.out.print("Enter Correct Option :");
            String an = sc.nextLine();




            if (!an.equals(c[i])){
                System.out.println("Wrong answer");

            }
            else {
                System.out.println("Correct  ans");
                score++;
            }
            System.out.println(" ");
        }
        System.out.println("Your Total Score is "+score+" out of 5");
    }

}
