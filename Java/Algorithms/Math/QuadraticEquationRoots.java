import java.util.*;

public class QuadraticEquationRoots{
	public static void main(String[] args) {
		Solutions s = new Solutions();
		System.out.print(s.quadraticRoots(752,904,164));
	}
}



class Solutions{
	public ArrayList<Integer> quadraticRoots(int a, int b, int c) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		int d = (b*b) -(4*a*c);
		int root1 = 0,root2 =0;
        if(d<0){
			list.add(-1);
		}else{
			root1 = (int)(-1*b + Math.sqrt(d))/(2*a);
			root2 = (int)(-1*b - Math.sqrt(d))/(2*a);
			
		}
		list.add(Math.max(root1, root2));
		list.add(Math.min(root1, root2));

		
		return list;	

    }

	
		
	
}



// #include <iostream>
// #include <cmath>
// using namespace std;
// int main() 
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//     double a, b, c, d, root1,root2, realPart, imaginaryPart;
//     cin>>a>>b>>c;
//     d = b*b-4*a*c;
//     if (d > 0)
//     {
//         root1 = (-b+sqrt(d))/(2*a);
//         root2 = (-b-sqrt(d))/(2*a);
//         cout<<floor(root1)<<" "<<floor(root2)<<endl;
//     }
//     else if (d == 0)
//     {
//         root1 = root2 = -b/(2*a);
//         cout<<floor(root1)<<" "<<floor(root2)<<endl;    }
//     else
//     {
//         cout<<"Imaginary"<<endl;
//     }
    
//     }
//  return 0;
// }