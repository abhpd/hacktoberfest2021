import java.util.Scanner;

class DigitPattern_0{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter the Height of 0 : ");
        int height = sc.nextInt();

        int i, j, space = (height / 3);
        int width = height / 2 + height / 5 + space + space;
    
        System.out.println();
        for (i = 0; i < height; i++) {
            for (j = 0; j <= width; j++) {
                if (j == width - (int)Math.abs(space)
                    || j == (int)Math.abs(space))
                    System.out.print("*");
                else if ((i == 0
                          || i == height - 1)
                         && j > (int)Math.abs(space)
                         && j < width - (int)Math.abs(space))
                         System.out.print("*");
                else
                System.out.print(" ");
            }
            if (space != 0
                && i < height / 2) {
                space--;
            }
            else if (i >= (height / 2 + height / 5))
                space--;
            System.out.println();
        }
    }
}