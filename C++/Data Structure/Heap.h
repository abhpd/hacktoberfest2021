
class Heap
{
  std::vector<int> heap;
  bool heapType;
  bool comparator(int left, int right);

public:
  Heap(bool heapType = MIN);
  void printHeap() const;
  void insert(int x);
  int extract();
  bool empty()
  {
    return heap.size() == 0;
  }
  int size()
  {
    return heap.size();
  }
  int top()
  {
    if (heap.empty())
    {
      throw std::logic_error("top : Heap empty");
    }
    return heap[0];
  }
};
#endif
