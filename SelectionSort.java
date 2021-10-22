import java.util.Scanner;

public class SelectionSort {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter how many number of elements you want in the a");
int n=sc.nextInt();
int a[]=new int[n];
for(int i=0;i<a.length;i++)
{
	a[i]=sc.nextInt();
}
System.out.println("Your array");
for(int l:a)
{
	System.out.print(l+" ");
}

System.out.println();

System.out.println("After selection sorting");
int m[]=arr(a);
for(int b:m)
{
	System.out.print(b+" ");
}
	}
static int[] arr (int a[])
{
	for(int i=0;i<a.length-1;i++)
	{ int minindex=i;
		for(int j=i;j<a.length;j++)
		{
			if(a[j]<a[minindex])
			{
				minindex=j;
			}
		int temp=a[i];
		a[i]=a[minindex];
		a[minindex]=temp;
		}
	}
return a;
}
}
