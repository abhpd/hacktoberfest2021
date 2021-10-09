import java.io.*; // for handling input/output
import java.util.*; // contains Collections framework


class Main {


    /**
        5 7 5 5 1 2 2, k = 4
        5 | 3
        7 | 1
        1 | 1
        2 | 2
        Max Heap = 1, 1, 1 = 3
        3 - 2
        2 - 1
        total = 7
        distinct = 4 - (4 - 3)
        difference = 3
    */


	public static void main (String[] args) throws IOException{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int t = Integer.parseInt(br.readLine());
            while(t-- > 0){
                String str[] = br.readLine().split(" ");
                int n = Integer.parseInt(str[0]);
                int k = Integer.parseInt(str[1]);
                HashMap<Integer, Integer> hm = new HashMap<>();
                str = br.readLine().split(" ");
                int value, duplicates = 0;
                for(int i = 0; i < n; i++){
                    value = Integer.parseInt(str[i]);
                    if(hm.containsKey(value)){
                        duplicates++;
                        hm.put(value, hm.get(value) + 1);
                    }
                    else{
                        hm.put(value, 1);
                    }
                }
                if(k <= duplicates){
                    System.out.println(hm.size());
                }                
                else{
                    System.out.println(hm.size() - (k - duplicates));
                }

            }
	}
}