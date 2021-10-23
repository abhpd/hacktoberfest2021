import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();

        int nspaces = n / 2;
        int nstars = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= nspaces; j++) {
                if (i != n / 2 + 1) {
                    System.out.print("\t");
                } else {
                    System.out.print("*\t");
                }
            }

            for (int j = 1; j <= nstars; j++) {
                System.out.print("*\t");
            }

            if (i <= n / 2) {
                nstars++;
            } else {
                nstars--;
            }

            System.out.println();
        }

    }
}
