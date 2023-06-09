// C++ program to demonstrate Ordered set DS in GNU C++
#include <iostream>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//required header files 
using namespace __gnu_pbds;
//required namespace
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// we have to give data type (here int is used)
int main()
{
	ordered_set M;
	// inserting 10 elements in ordered_set
	M.insert(5);
	M.insert(1);
	M.insert(2);
    M.insert(11);
    M.insert(7);
    M.insert(8);
    M.insert(9);
    M.insert(14);
    M.insert(13);
    M.insert(15);
    /* Ordered set are similar to set in C++ STL except they have 2 extra functions namely
      1. find_by_order -> returns an iterator to the kth element (0 based indexing)
      2. order_of_key  -> returns no of elements strictly less than k 
    */
      
    //after inserting above elements M should look like
    //M -> 1 2 5 7 8 9 11 13 14 15
      
    //finding 3rd elment in set
    cout<<"3rd element in set is: "<< *M.find_by_order(2)<<endl; //should print 5
    //finding last element in set
    cout<<"last element in set is: "<< *M.find_by_order(6)<<endl; // should print 11
    
	//finding no elements strictly less than 8
	cout<<"no elements strictly less than 8 : "<< M.order_of_key(8)<<endl;
	//even if that exact no is not present, we can still find no of elements which are less than that
	//finding no of elements less than 6 
	cout<<"no of elements strictly less than 6 : "<< M.order_of_key(6)<<endl;
	
	// Deleting 1 from the set if it exists
	if (M.find(1) != M.end()){
	    M.erase(M.find(1));
	}
	
	// Now after deleting 1 from the set
	// finding the smallest element in the set
	cout <<"smallest element after deleting 1: "<<*(M.find_by_order(0))<< endl;
		
    //finding the element which is less than 10 and is nearest to 10
    cout<<"the element which is less than 10 and is nearest to 10: "<<*M.find_by_order(M.order_of_key(10)-1) << endl;
    
    //finding no of elements in the range [5,15) 
    cout<<"no of elements in the range [5,15): "<<M.order_of_key(15) - M.order_of_key(5) <<endl;

	return 0;
}
