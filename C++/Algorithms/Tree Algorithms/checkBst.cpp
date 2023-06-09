#include<iostream>
#include<queue>
using namespace std;

struct BstNode{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

BstNode* Insert(BstNode* root, int data){
    if(root == nullptr){
        root = GetNewNode(data);
    }
    else if(data <= root->data){
        root->left = Insert(root->left, data);
    }
    else{
        root->right = Insert(root->right, data);
    }
    return root;
}

//To check is binary tree BST or not
bool IsBstUtil(BstNode *root, int minValue, int maxValue){
    if(root == nullptr) return true;
    if(root->data > minValue && root->data < maxValue && IsBstUtil(root->left, minValue, root->data) && IsBstUtil(root->right, root->data, maxValue)){
        return true;
    }
    else return false;
}

bool IsBinarySeachTree(BstNode *root){
    return IsBstUtil(root, INT_MIN, INT_MAX);
}

int main(){
    BstNode *root = nullptr; // pointer to root node, set to null.
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 30);
    root = Insert(root, 40);
    root = Insert(root, 50);
    root = Insert(root, 25);

    cout<<IsBinarySeachTree(root);
}