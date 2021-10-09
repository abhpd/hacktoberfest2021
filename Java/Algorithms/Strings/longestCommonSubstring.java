
public class longestCommonSubstring {
    static String s1,s2;
    public static void main(String args[]){
        s1 = "GeeksForGeeks";
        s2 = "GeeksSmart";
        int count = lcs(s1.length(),s2.length(),0);
        System.out.println(count);
    }

    static int lcs(int n1, int n2, int count){
        if(n1 == 0 || n2 == 0) return count;
        if(s1.charAt(n1-1) == s2.charAt(n2-1)) return lcs(n1-1,n2-1,count+1);
        count = Math.max(count,Math.max(lcs(n1-1,n2,0),lcs(n1,n2-1,0)));
        return count;
    }
}
