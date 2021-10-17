package Java;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;


public class buffer {
    public static void main(String[] args) {

    InputStreamReader streamReader=new InputStreamReader(System.in);
    BufferedReader bufferedReader = new BufferedReader(streamReader);

        System.out.println("Program penjumlahan sangat sederhana");
        int value = 0;
        int anotherValue=0;
        try{
            System.out.println("Masukan angka pertama :");
            value= Integer.parseInt(bufferedReader.readLine());
            System.out.println("Masukan angka kedua :");
            anotherValue=Integer.parseInt(bufferedReader.readLine());



        }catch (Exception e){
            e.printStackTrace();

        }
        int result= value + anotherValue;
        System.out.printf("hasil penjumlahan %d dan %d adalah %d",value,anotherValue,result);






    }
}
