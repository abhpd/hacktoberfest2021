// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}


class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void push_left_nodes(Node*root, stack<Node*>& stk)
    {
        while(root)
        {
            stk.push(root);
            root=root->left;
        }
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       stack<Node*> stk1,stk2;
       push_left_nodes(root1, stk1);
       push_left_nodes(root2,stk2);
       Node*i= stk1.top();
       Node*j=stk2.top();
      
       vector<int> ans;
      while( stk1.size()>0 && stk2.size()>0 )
      {
           
          if(i->data < j->data)
          {
              ans.push_back(i->data);
              stk1.pop();
              push_left_nodes(i->right,stk1);
              if(stk1.size()==0)
                break;
              i=stk1.top();
          }
          else
          {
            ans.push_back(j->data);
            stk2.pop();
            push_left_nodes(j->right,stk2);
            if(stk2.size()==0)
                break;
            j=stk2.top();
             
          }
      }
      while(!stk1.empty())
      {
          ans.push_back(i->data);
          stk1.pop();
          push_left_nodes(i->right,stk1);
          if(stk1.size()==0)
            break;
          i=stk1.top();
           
      }
        while(! stk2.empty())
        {
          ans.push_back(j->data);
          stk2.pop();
          push_left_nodes(j->right,stk2);
          if(stk2.size()==0)
             break;
          j=stk2.top();
        }
        return ans;
    }
};


int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
   }
   return 0;
}  


// Sample Input
// Test cases followed by the leve order traversal of trees.
// 1
// 5 3 6 2 4
// 2 1 3 N N N 7 6