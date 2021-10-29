import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

class Parameter{
    String Name;
    String Type;
    int size;

    Parameter(String X){
        String[] arr = X.split(",");
        Name = arr[0];
        Type = arr[1];
        size = Integer.parseInt(arr[2].trim());
    }

    void display(){
        System.out.println("Field: "+Name+", Type: "+Type+", Size: "+size);
    }
}

public class program1_2017 {
    public static void main(String[] args) throws IOException {
        FileReader meta = new FileReader("metadata.txt");
        int a;
        String x = "";
        while ((a=meta.read())!=-1){
            x = x+((char)a);
        }
        meta.close();
        String[] arr = x.split("\n");
        ArrayList<Parameter> MetDat = new ArrayList<>();
        for (int i=0;i<arr.length;i++){
            MetDat.add(new Parameter(arr[i]));
        }
        for (int i=0;i<MetDat.size();i++){
            MetDat.get(i).display();
        }

        File file = new File("db.data");
        FileInputStream data = new FileInputStream(file);
        byte[] buffer = new byte[(int) file.length()];
        data.read(buffer);
        data.close();
        x = "";
        for(int i=0;i<buffer.length;i++){
            x = x + ((char)buffer[i]);
        }
        String[] DataArr = x.split("\n");
        String[][] Dat = new String[DataArr.length][MetDat.size()];
        for(int i=0;i<DataArr.length;i++){
            String y = DataArr[i];
            int s = 0;
            for (int j=0;j<MetDat.size();j++){
                if(!(j==(MetDat.size()-1))) {
                    int k = MetDat.get(j).size;
                    Dat[i][j] = (y.substring(s, s + k)).trim();
                    s = s + k;
                }
                else{
                    int k = MetDat.get(j).size;
                    Dat[i][j] = (y.substring(s)).trim();
                    s = s+k;
                }
            }
        }

        System.out.println();
        System.out.println("Finish reading data description file....");
        System.out.println();
        System.out.println("The data file contains these records:");
        for(int i=0;i<Dat.length;i++){
            for (int j=0;j<Dat[i].length;j++){
                System.out.print(Dat[i][j]+" ");
            }
            System.out.println();
        }

        String z = args[0];

        int q =-1;
        for (int i=0;i<MetDat.size();i++){
            if ((MetDat.get(i).Name.toLowerCase()).equals(z.toLowerCase())){
                q = i;
            }
        }

        System.out.println();
        System.out.println("Find max value in the field "+z);
        if(q!=-1){
            String Type = MetDat.get(q).Type;
            if(Type.equals("I")){
                int[] maxarr = new int[Dat.length];
                for (int i=0;i<Dat.length;i++){
                    maxarr[i]=Integer.parseInt(Dat[i][q]);
                }
                Arrays.sort(maxarr);
                System.out.println("Max: "+maxarr[Dat.length-1]);
            }
            else if(Type.equals("C")){
                String[] maxarr = new String[Dat.length];
                for (int i=0;i<Dat.length;i++){
                    maxarr[i]=Dat[i][q];
                }
                Arrays.sort(maxarr);
                System.out.println("Max: "+maxarr[Dat.length-1]);
            }
            else if(Type.equals("F")){
                float[] maxarr = new float[Dat.length];
                for (int i=0;i<Dat.length;i++){
                    maxarr[i]=Float.parseFloat(Dat[i][q]);
                }
                Arrays.sort(maxarr);
                System.out.println("Max: "+maxarr[Dat.length-1]);
            }
            else if(Type.equals("D")){
                double[] maxarr = new double[Dat.length];
                for (int i=0;i<Dat.length;i++){
                    maxarr[i]=Double.parseDouble(Dat[i][q]);
                }
                Arrays.sort(maxarr);
                System.out.println("Max: "+maxarr[Dat.length-1]);
            }
        }
        else{
            System.out.println("---Error: field not found");
        }
    }
}