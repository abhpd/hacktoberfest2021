// C++ program for printing vertical
// order of a given binary tree using BFS
#include <bits/stdc++.h>
 
using namespace std;
 
/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
	int data; 
	struct Node* left, *right; 
	Node(int data) 
	{ 
		this->data = data; 
		left = right = NULL; 
	} 
}; 
 
// The main function to print vertical
// order of a binary tree with given root
void printVerticalOrder(Node* root)
{
    // Base case
    if (!root) return;
 
    // Create a map and store vertical
    // order in map using
    // function getVerticalOrder()
    unordered_map<int, vector<int> > m;
    int hd = 0;
 
    // Create queue to do level order
    // traversal Every item of queue contains
    // node and horizontal distance
    queue<pair<Node*, int> > q;
    q.push({root, hd});
   
    // mn and mx contain the minimum and
      // maximum horizontal distance from root
    int mn=0,mx=0;
    while (!q.empty()) {
       
        // pop from queue front
        pair<Node*, int> temp = q.front();
        q.pop();
        hd = temp.second;
        Node* node = temp.first;
 
        // insert this node's data
          // in vector of hash
        m[hd].push_back(node->data);
 
        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
       
        // Update mn and mx
        if(mn>hd)
          mn=hd;
        else if(mx<hd)
          mx=hd;
    }
 
    // run the loop from minimum to maximum
    // every horizontal distance hd
    for (int i=mn;i<=mx;i++)
    {
        vector<int> tmp=m[i];
        for(int j=0;j<tmp.size();j++)
          cout<<tmp[j]<<" ";
        cout<<endl;
      }
}
 
// Driver program to test above functions
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
    root->right->right->left = new Node(10);
    root->right->right->left->right = new Node(11);
    root->right->right->left->right->right = new Node(12);
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;
}