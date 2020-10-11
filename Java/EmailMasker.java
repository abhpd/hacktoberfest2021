public class EmailMasker {

    private static final String ATSIGN = "@";
    private static final char DOT_CHAR = '.';
    private static final char ASTERISK_CHAR = '*';
    private static final int ONE = 1;

    /**
        Email input must be valid and return a masked email
         input: abc.edf@gmail.com
         output: a**.**f@gmail.com
     */
    public String maskEmail(String email) {
        StringBuilder sb = new StringBuilder(email);
        int beforeAtIndexPos = sb.indexOf(ATSIGN) - ONE;
        for (int i = ONE; i < beforeAtIndexPos; i++) {
            if (sb.charAt(i) != DOT_CHAR) {
                sb.setCharAt(i, ASTERISK_CHAR);
            }
        }
        return sb.toString();
    }
}