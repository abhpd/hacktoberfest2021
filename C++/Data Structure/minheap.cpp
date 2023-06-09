#include<iostream>
#include<math.h>

using namespace std;

void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

class minHeap{
	private:
		int *harr;
		int capacity;
		int heap_size;
	public:
		minHeap(int cap){
			heap_size = 0;
			capacity = cap;
			harr = new int[cap];
		}
		int parent(int i){
			return (i-1)/2;
		}
		int left(int i){
			return (2 * i + 1);
		}
		int right(int i){
			return (2 * i + 2);
		}
		int getMin(){
			return harr[0];
		}
		
		void insertVal(int val){
			if(heap_size == capacity){
				cout<<"could not insert value heap full";
				return;
			}
			heap_size++;
			int i = heap_size-1;
			harr[i] = val;
			while(i!=0 && harr[i] < harr[parent(i)]){
				swap(harr[i], harr[parent(i)]);
				i = parent(i);
			}
		}
		int extractMin(){
			if(heap_size <= 0)
				return 0;
			if(heap_size == 1){
				heap_size--;
				return(harr[0]);
			}
			int root = harr[0];
			harr[0] = harr[heap_size-1];
			heap_size--;
			minHeapify(0);
			return root;
		}
		
		void decreaseVal(int i, int new_val){
			harr[i] = new_val;
			while(i!=0 && harr[i] < harr[parent(i)]){
				swap(harr[i], harr[parent(i)]);
				i = parent(i);
			}
		}
		
		void deleteVal(int i){
			decreaseVal(i, INT_MIN);
			extractMin();
		}
		
		void minHeapify(int i){
			int l = left(i);
			int r = right(i);
			int smallest = i;
			if(harr[l] < harr[i] && l < heap_size)
				smallest = l;
			if(harr[r] < harr[smallest] && r < heap_size)
				smallest = r;
			if(smallest != i){
				swap(harr[i], harr[smallest]);
				minHeapify(smallest);
			}
		}

		void search(int val){
			for(int i = 0; i < heap_size; i++){
				if(harr[i] == val){
					cout << "Value Found!"<<endl;
					return;
				}
			}
			cout << "Value not found!"<<endl;
		}
		
		void printHeap(){
			for(int i = 0; i < heap_size; i++)
				cout << harr[i] << " ";
			cout << endl;
		}
		int height(){
			return ceil(log2(heap_size + 1)) - 1;
		}

};

int main(){
	int s;
	cout << "Enter size of the Min Heap: ";
	cin >> s;
	minHeap mh(s);
	cout << "Min Heap Created" << endl;
	
	int ch, val;
	while(true){
		cout<<"1. Insert()"<<endl;
		cout<<"2. Search()"<<endl;
		cout<<"3. Delete()"<<endl;
		cout<<"4. Get Minimum()"<<endl;
		cout<<"5. Extract Minimum()"<<endl;
		cout<<"6. Height()"<<endl;
		cout<<"7. Print()"<<endl;
		cout<<"8. Exit()"<<endl;
		cout<<"Enter Choice: ";
		cin >> ch;
		
		switch(ch){
			case 1:
				cout<<"Insert Operation"<<endl;
				cout<<"Enter value: ";
				cin>>val;
				mh.insertVal(val);
				break;
			case 2:
				cout<<"Search Operation"<<endl;
				cout<<"Enter a value to search: ";
				cin>>val;
				mh.search(val);
				break;
			case 3:
				cout<<"delete Operation"<<endl;
				cout<<"Enter index of the heap element to delete: ";
				cin>>val;
				mh.deleteVal(val);
				break;
			case 4:
				cout<<"Get Minimum Operation"<<endl;
				cout << "Get Minimum Value = " << mh.getMin()<<endl;
				break;
			case 5:
				cout<<"Extract Minimum Operation"<<endl;
				cout << "Extract Minimum Value = " << mh.extractMin()<<endl;
				break;
			case 6:
				cout<<"Height Operation"<<endl;
				cout << "Height = " << mh.height()<<endl;
				break;
			case 7:
				cout<<"Print Operation"<<endl;
				mh.printHeap();
				break;
			case 8:
				exit(0);
			default:
				cout << "Enter valid choice" << endl;
		}
	}
	return 0;
}



