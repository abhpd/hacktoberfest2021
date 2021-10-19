#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> a;
	vector<int> b(5, 10); // five int with value 10
	vector<int> c(b.begin(), b.end());
	vector<int> d{1, 2, 3, 4, 5};

	// Iterating over a vector
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	} cout << endl;

	for (auto it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	} cout << endl;

	/* The vector class has in it defined an iterator.
	Here the data type of it is vector<int>::iterator */

	// For each loop
	for (int x : c) {
		cout << x << " ";
	} cout << endl;

	vector<int> v;
	int n = 5;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num); // Adds an element to end of the vector
	}

	// Difference between v and d
	cout << v.size() << endl;
	cout << v.capacity() << endl; // size of underlying array Ans: 8
	cout << v.max_size() << endl; // maximum no. of elements that a vector can hold in worst case acc to avlb memory

	cout << d.size() << endl;
	cout << d.capacity() << endl; // Ans: 5
	cout << d.max_size() << endl;
}


// Some modifiers that can be used with vectors-
// assign() – It assigns new value to the vector elements by replacing old ones
// push_back() – It push the elements into a vector from the back
// pop_back() – It is used to pop or remove elements from a vector from the back.
// insert() – It inserts new elements before the element at the specified position
// erase() – It is used to remove elements from a container from the specified position or range.
// swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
// clear() – It is used to remove all the elements of the vector container
// emplace() – It extends the container by inserting new element at position
// emplace_back() – It is used to insert a new element into the vector container, the new element is added to the end of the vector
