/* Sample Input:
2
abababcdefababcdab
gccksfvrgccks

Sample Output:
6
7
*/

import java.util.Scanner;

public class LongestDistinctCharacters {

    static int maxLength(String str) {
        if (str.length() == 0) {
            return 0;
        }

        int start = 0, end = 0, ans = 1, i;
        char cur_c;

        while (true) {
            if (end == str.length()-1) {
                break;
            }
            end++;

            cur_c = str.charAt(end);
            for(i=start; i<end; i++){
                if(cur_c == str.charAt(i)) {
                    break;
                }
            }
            if (i != end) {
                start = i + 1;
            }
            if (ans < (end-start+1)){
                ans = end - start + 1;
            }
        }
        return ans;
    }

	public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T>0){
            String str = sc.next();
            System.out.println(maxLength(str));
            T--;
            
        }
        sc.close();
	}
}
