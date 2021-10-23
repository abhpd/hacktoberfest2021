/**
 * 
 * @author Varun
 *
 */
public class RepeatedSubstring {

	public static void main(String[] args) {

		String s="ababc";
		System.out.println(repeatedStringPattern(s));
	}

	private static boolean repeatedStringPattern(String s) {
		// TODO Auto-generated method stub
		int length = s.length();
		 int i=1;
	        while(i <= length/2){
	          if(length %i == 0){
	              String str=s.substring(0,i);
	              int m=length / i;
	              StringBuilder sb= new StringBuilder();
	              int j=0;
	              while(j++ < m){
	                  sb.append(str);
	              }
	              if(sb.toString().equals(s)){
	                  return true;
	              }
	              i++;
	          }  
	        }
		return false;
		
	}

}
