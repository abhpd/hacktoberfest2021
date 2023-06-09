import java.util.*;
public class Main
{
    static void permute(int l,int r,String str)
    {
        if(l==r)
        {
            System.out.println(str);
        }
        else
        {
        
        
            for(int i=l;i<r;i++)
            {
                //s+=str.charAt(l);
                
                
                
                
                char[] charArray = str.toCharArray();
                char temp = charArray[i] ;
                charArray[i] = charArray[l];
                charArray[l] = temp;
                str =  String.valueOf(charArray);
                
                subString(l+1,r,str);
                
                charArray = str.toCharArray();
                temp = charArray[i] ;
                charArray[i] = charArray[l];
                charArray[l] = temp;
                str =  String.valueOf(charArray);
                
                
            }
        }
    }
    
    
    
	public static void main(String[] args) {
		
		String s = "abc";
		permute(0,s.length(),s);
	}
}

