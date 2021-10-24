// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Brute Force Approach - We can simply use a vector to store all nodes in it and after that sort the vector and make a linkedlist out of the sorted vector . Time Complexity : O(NlogN) where N is the total number of nodes , Space Complexity O(N)

/*
-----------------Better Approach (comapre one by one)----------------- 
Compare every k nodes (head of every linked list) and get the node with the smallest value.
Extend the final sorted linked list with the selected nodes.

Time Complexity : O(K * N)  K is number of lists . Almost every selection of node in final linked costs O(K) (k-1 times comparison).There are N nodes in the final linked list.
Space Complexity : O(N)
*/

/*
------------Optimized Better Approach (priority queue)------------
 use a min heap of size k to get the smallest of k nodes in log K time , and keep adding the smallest node and pushing the next node form that list until the heap becomes empty.
 
 Time Complexity : O(N log K) ,
 The comparison cost will be reduced to O(log K) for every pop and insertion to priority queue. But finding the node with the smallest value just costs O(1) time. There are NN nodes in the final linked list.

 Space Comlpexity : O(K) . The max size of priority queue
*/

class comparator
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // creating a priority queue(min heap) of ListNodes .
        // priority_queue supports a constructor that requires two extra arguments to make it min-heap
        priority_queue<ListNode *, vector<ListNode *>, comparator> min_heap;

        // a dummyNode a to mark the head of K Merged Lists
        ListNode *dummyNode = new ListNode(-1);

        // tail to keep track of last added node in K Merged Lists
        ListNode *tail = dummyNode;

        // push the k sorted lists into the min heap
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != nullptr)
                min_heap.push(lists[i]);
        }

        // while min heap is not empty
        while (min_heap.size())
        {

            // create a node to store the min_node from min Heap
            ListNode *minFormHeap = min_heap.top();
            // remove the smallest node form min heap
            min_heap.pop();

            // add the smallest node to next of tail pointer
            tail->next = minFormHeap;
            // move tail to the last node in List
            tail = minFormHeap;

            // Adding the next element form the list from which the smallest node belongs . if its not null
            if (minFormHeap->next != nullptr)
                min_heap.push(minFormHeap->next);
        }

        // return the head
        return dummyNode->next;
    }
};

/*
-------- The Optimal Approach - Merge with Divide And Conquer --------
 This approach walks alongside the one above but is improved a lot. We don't need to traverse most nodes many times repeatedly

Pair up k lists and merge each pair.

After the first pairing, k lists are merged into k/2 lists with average 2N/k length, then k/4, k/8 and so on.

Repeat this procedure until we get the final sorted linked list.

Thus, we'll traverse almost N nodes per pairing and merging, and repeat this procedure about log k times.  
*/