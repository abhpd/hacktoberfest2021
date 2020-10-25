import java.util.*;
class linearsearch{
	static int search(int a[],int x){
			for(int k=0;k<a.length;k++){
			  if(x==a[k]){
				  return k;
			  }
			}
			return -1;
		}
	public static void main(String [] args){
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter the the size of array:");
		int n=sc.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++){
			System.out.print("Enter the value at index "+i+":");
			a[i]=sc.nextInt();
		}
		System.out.print("Your array is: ");
		for(int j=0;j<n;j++){
			System.out.print(a[j]+" ");
		}
		System.out.print("\nEnter the value you wanna search:");
		int x=sc.nextInt();
		int result=search(a,x);
		if(result==-1){
			System.out.print("Value doesn't exist in array");
		}
		else{
			System.out.print("Index where the value exist is:"+result);
		}
	}
}
