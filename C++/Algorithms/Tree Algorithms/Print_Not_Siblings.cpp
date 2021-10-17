/*Nodes without sibling
Given a binary tree, print all nodes that don’t have a sibling.
Edit : Print the elements in different lines. And order of elements doesn't matter.
Input format :
Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.
Output format :
Print nodes separated by new line.
Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
9
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BinaryTreeNode
{   
    public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
    
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>* takeinput() // Level Wise Input
{
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    if(rootData==-1)
    return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);
    while(pending.size()!=0)
    {
        cout<<"Enter Left Data of "<<pending.front()->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1)
        {
            BinaryTreeNode<int>* left = new BinaryTreeNode<int>(leftData);
            pending.front()->left = left;
            pending.push(left);
        }
        
        cout<<"Enter Right Data of "<<pending.front()->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1)
        {
            BinaryTreeNode<int>* right = new BinaryTreeNode<int>(rightData);
            pending.front()->right = right;
            pending.push(right);
        }
        pending.pop();
    }
    return root;
}

void print(BinaryTreeNode<int>* root)   // Level Wise Print
{
    if(root==NULL)
    return ;
    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);
    while(pending.size()!=0)
    {
        cout<<pending.front()->data<<":";

        if(pending.front()->left==NULL)
            cout<<" L->";
        
        if(pending.front()->left!=NULL)
        {
            cout<<" L->"<<pending.front()->left->data;
            pending.push(pending.front()->left);
        }

        if(pending.front()->right==NULL)
            cout<<" R->";

        if(pending.front()->right!=NULL)
        {
            cout<<" R->"<<pending.front()->right->data;
            pending.push(pending.front()->right);
        }
        cout<<endl;

        pending.pop();
    }
}

void printnotsiblings(BinaryTreeNode<int>* root) // Function to Print Nodes without Siblings
{
    if(root==NULL)
    return;
    if(root->left!=NULL && root->right!=NULL)
    {
        printnotsiblings(root->left);
        printnotsiblings(root->right);
    }
    else if(root->left!=NULL)
    {
        cout<<root->left->data<<" ";
        printnotsiblings(root->left);
    }
    else if(root->right!=NULL)
    {
        cout<<root->right->data<<" ";
        printnotsiblings(root->right);
    }
}

int main()
{
    BinaryTreeNode<int>* root = takeinput();
    print(root);
    cout<<endl;
    printnotsiblings(root);
    return 0;
}
