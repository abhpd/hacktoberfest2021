 
import java.util.*;
class ButterfltPattern {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i,j,k,n=5,m;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++) {
				System.out.print("*");
				
			}
			
			for(k=2*(n-i);k>0;k--)
			{
				System.out.print(" ");
			}
			for(m=i;m>0;m--)
			{
				System.out.print("*");
			}
			System.out.println();
		}
		for(i=n;i>0;i--)
		{
			for(j=1;j<=i;j++) {
				System.out.print("*");
				
			}
			
			for(k=2*(n-i);k>0;k--)
			{
				System.out.print(" ");
			}
			for(m=i;m>0;m--)
			{
				System.out.print("*");
			}
			System.out.println();
		}

	}

}
