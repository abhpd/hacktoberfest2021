
import java.io.*; 
import java.util.*; 


class ReplaceElement {
	
            public static int i;

 public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);
  int N = sc.nextInt();
  int[] na = new int[N];
  int[] a = new int[N];
  for (int i = 0; i < N; i++)
   a[i] = sc.nextInt();
  for (i = 0; i < N; i++) {
   if (i == 0) {
    na[i] = a[i] * a[i + 1];
   }
   else {
    if (i == N - 1) {
     na[i] = a[i] * a[i - 1];
    } else
     na[i] = a[i - 1] * a[i + 1];
   }
  }
  for (i = 0; i < N; i++)
   System.out.print(na[i] + " ");
 }
}
