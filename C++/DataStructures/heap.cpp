
#include "heap.h"
using namespace std;

Heap::Heap(bool heapType) : heapType(heapType) {
  cout << "\n Heap Created of"; 
  heapType ? cout << " Max Type" : cout << " Min Type"; 
}

inline bool Heap::comparator(int left, int right) {
  if(heapType) {  
    return left > right;
  } else {
    return left < right;
  }
}

void Heap::printHeap() const {
  if(heap.empty()) return;
  int parent = 0;
  int left = 1;
  int right = 2;
  queue<int> level;
  level.push(parent);
  int size = 1;
  cout << "\n";
  int temp = 1;
  while(!level.empty()) { 
    temp = size;
    while(!level.empty() && temp-- != 0) {
      parent = level.front(); level.pop();
      cout << "\t" << heap[parent] << "\t";
      left = 2*parent + 1;
      right = 2*parent + 2;
      if(left <  heap.size())
        level.push(left);
      if(right < heap.size())
        level.push(right);
    }
    cout << "\n";
    size *= 2;
  }
  cout << "\n";
}

void Heap::insert(int x) {  
  int pos = heap.size();
  heap.push_back(x);
  if(heap.size() > 1) {
    int parent = (int) ((pos-1)/2 + 0.5);
    while(pos > 0 && comparator(heap[pos], heap[parent])) {
      int temp = heap[pos];
      heap[pos] = heap[parent];
      heap[parent] = temp;
      pos = parent;
      parent = (int) ((pos-1)/2 + 0.5);
    }
  }
}

int Heap::extract() {
  if(heap.empty()) {
    throw std::logic_error("extractMin : Heap empty");
  }
  int ret = heap[0];
  if(heap.size() == 1) {
    heap.clear();
  } else {
    heap[0] = *(--heap.end());
    heap.erase(heap.end() -1);
    int current = 0;
    int left = 1;
    int right = 2;
    while(right < heap.size() && ( comparator(heap[left], heap[current]) || comparator(heap[right], heap[current]))) {
      int pos = comparator(heap[left] , heap[right]) ? left : right;
      int temp = heap[current];
      heap[current] = heap[pos];
      heap[pos] = temp;
      current = pos;
      left = pos*2 + 1;
      right = pos*2 + 2;
    }
    if(left < heap.size() && comparator(heap[left],heap[current])) {
      int temp = heap[current];
      heap[current] = heap[left];
      heap[left] = temp;
    }
  }
  return ret;
}

int main() {
  Heap h(true);
  int arr[] = {7,3,2,1,4};
  for(int i = 0; i < 5; i++) {
    h.insert(arr[i]);
  }
  cout << "\n";
  while(!h.empty()) {
    cout << h.extract() << " ";
  }

}

