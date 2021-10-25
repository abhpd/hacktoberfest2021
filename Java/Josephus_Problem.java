import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Josephus_Problem {

    static boolean kill(List<Integer> list, boolean start){
        int last = list.get(list.size()-1);

        if(start){
            for(int i=0;i< list.size()-1;i++){
                list.remove(i+1);
            }
        }else{
            for(int i=0;i<list.size();i++){
                list.remove(i);
            }
        }

        return last != list.get(list.size() - 1);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        //System.out.println("Give n");
        int n = scanner.nextInt();

        List<Integer> list = new ArrayList<>(n);

        for(int i=0;i<n;i++){
            list.add(i+1);
        }

        boolean start = true;
        while(list.size()!=1){
            start = kill(list,start);
            //System.out.println(list);
        }

        System.out.println(list.get(0));
    }
}
