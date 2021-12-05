// C++ program for right view of tree  
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

// Returns a vector which contains right side view of binary tree
vector<int> right_view(struct Node* root)
{
    queue<Node*> q;
    vector<int> res;
    if(!root)
        return res;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        while(n--)
        {
            Node* p=q.front();
            q.pop();
            if(n==0)
            { 
                res.push_back(p->data);
            }
            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);
        }
    }
    return res;
}
/* Driver program to test above functions*/
int main() 
{ 
	struct Node *root = new Node(1); 
	root->left		  = new Node(2); 
	root->right		  = new Node(3); 
	root->left->left  = new Node(4); 
	root->left->right = new Node(5); 

	cout << "Right view of binary tree is \n"; 
	vector<int> p=right_view(root);
    for(auto i:p)
        cout<<i<<" ";
    cout<<endl;
	return 0; 
} 