#include<iostream>
#include<queue>
using namespace std;
 
struct node{

    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printLevelOrder(node *root){

    if(!root) return;

    queue<node*> q;
    q.push(root);      // we add root and NULL to queue
    q.push(NULL);

    while(!q.empty()){
        node* node = q.front();  // select the front most node to print
        q.pop();

        if(node){

            cout<<node->data<<" "; // print node
            if(node->left)         
            q.push(node->left);    // if the node has left children, add them to queue
            if(node->right)
            q.push(node->right);   // if the node has right children, add them to queue
        }
        else if(!q.empty())     // if we encounter a null, we check if we get an empty queue by removing it
        q.push(NULL);           // if queue is not empty, we add NULL back 
    }
}

int main(){
    
/*
            1
           / \
          2   3
         / \ / \
        4  5 6  7
*/
    node *root = new node(1);
    root->left = new node(2);    
    root->right = new node(3);  
    root->left->left = new node(4);  
    root->left->right = new node(5);
    root->right->left = new node(6);  
    root->right->right = new node(7);  
 
    printLevelOrder(root);
    return 0;
}