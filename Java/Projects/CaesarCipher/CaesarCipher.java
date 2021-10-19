public class CaesarCipher {

    public static void main(String[] args) {
        if (args.length != 2) {
            throw new IllegalArgumentException(
                    "You should specify the text as the first argument and an offset as the second argument");
        }
        String text = args[0].toLowerCase();
        int offset = Integer.parseInt(args[1]);
        int alphabetLength = 26;
        for (int i = 0; i < text.length(); i++) {
            char ch = text.charAt(i);
            if (!Character.isAlphabetic(ch)) {
                System.out.print(ch);
            }
            else {
                System.out.print((char) ('a' + (ch - 'a' + offset) % alphabetLength));
            }
        }
    }
}