// Median in a running stream using priority_queue

#include<iostream>
#include<queue>
using namespace std;
int main(){
	
	priority_queue<int> max_heap;                                  //max-heap
	priority_queue<int,vector<int>,greater<int>> min_heap;         //min-heap
	
	int d; cin>>d;
	float median = d;                                              //for first input median will be same as first input
  
	cout<<"m= "<<d<<endl;
  
	max_heap.push(d);
	cin>>d;
  
	while(d!=-1){
		
		if(d<=median){
			max_heap.push(d);
			if(max_heap.size() > min_heap.size()){
				min_heap.push(max_heap.top());
				max_heap.pop();
			}
		}
		else{
			min_heap.push(d);
			if(min_heap.size() > max_heap.size()){
				max_heap.push(min_heap.top());
				min_heap.pop();
			}
		}
    
		if(min_heap.size() == max_heap.size()) median=float((max_heap.top()+min_heap.top()))/2.00;
		else if(min_heap.size() > max_heap.size())  median=min_heap.top();
		else median =max_heap.top();
		cout<<"m= "<<median<<endl;
		cin>>d;
	}
	
	return 0;
}
