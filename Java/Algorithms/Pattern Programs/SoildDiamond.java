/*
 
Solid Diamond Problem
             *
            * *
           * * *
          * * * *
         * * * * *
          * * * *
           * * *
            * *
             *
*/

// Here is a function in which you can any number of row
// ans get soild diamond pattern for that 

public static  void solidDiamond(int n){

    for (int row = 1; row < 2 * n ; row++) {

        int totalColInRow = row > n ? 2 * n - row : row;
        int numberOfSpaces = n - totalColInRow ;

        for (int col = 0; col < numberOfSpaces ; col++) {
            System.out.print(" ");
        }


        for (int col = 0; col < totalColInRow ; col++) {
            System.out.print("* ");
        }
        System.out.println();
    }

}