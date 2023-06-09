/* Delete a node from BST   */

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int x){
    Node* temp=new Node;
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

Node* Insert(Node* root,int x){
    if(root==NULL){
        root=GetNewNode(x);
    }
    else if(x<root->data){
        root->left=Insert(root->left,x);
    }
    else{
        root->right=Insert(root->right,x);
    }
    return root;
}

Node* FindMin(Node* root){
    if(root==NULL){
        cout<<"Empty"<<endl;
        return NULL;
    }
    else if(root->left==NULL){
        return root;
    }
    else
        return FindMin(root->left);
}

//Delete ftn
Node* Delete(Node* root,int data){

    if(root==NULL) return root;
    else if(data<root->data)
        root->left=Delete(root->left,data);
    else if(data>root->data)
        root->right=Delete(root->right,data);
    else{  //we've found the node to be deleted

        //case 1:No child
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL; //to avoid dangling pointer
        }

        //case 2: One child
        else if(root->left==NULL){
            Node* temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL){
            Node* temp=root;
            root=root->left;
            delete temp;
        }

        //case 3: 2 children
        else{
            Node* temp=FindMin(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }

    return root;  //important
}

//to traverse and print
void InOrder(Node* root){
    if(root==NULL) return;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

int main()
{
    Node * root= NULL;  //keeping root as local variable
    int range,x;
    cout<<"how many elements :";
    cin>>range;
    for(int i=0;i<range;i++){
        cout<<"enter element: ";
        cin>>x;
        root=Insert(root,x);
    }

    InOrder(root);

    Delete(root,10);
    cout<<endl;
    InOrder(root);
    return 0;
}

