
public class LinearSearch {
    public static void main(String[] args) {
        // Validate command line arguments count.

        if (args.length != 2)
        {
            System.err.println("usage: java LinearSearch integers integer");
            return;
        }

        // Read integers from first command-line argument. Return if integers
        // could not be read.

        int[] ints = readIntegers(args[0]);
        if (ints == null)
            return;

        // Read search integer; NumberFormatException is thrown if the integer
        // isn't valid.

        int srchint = Integer.parseInt(args[1]);

        // Perform the search and output the result.

        System.out.println(srchint + (search(ints, srchint) ? " found"
                : " not found"));
    }

    private static int[] readIntegers(String s)
    {
        String[] tokens = s.split(",");
        int[] integers = new int[tokens.length];
        for (int i = 0; i < tokens.length; i++)
            integers[i] = Integer.parseInt(tokens[i]);
        return integers;
    }

    private static boolean search(int[] x, int srchint)
    {
        for (int i = 0; i < x.length; i++)
            if (srchint == x[i])
                return true;

        return false;
    }
    }
}