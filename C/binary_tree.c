#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createTree(){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    int x;
    printf("Enter the data (-1 for no node) \n");
    scanf("%d",&x);
    if(x == -1){
        return 0;
    }
    newNode->data = x; 

    printf("Enter the left child of %d \n",x);
    newNode->left = createTree();

    printf("Enter the right child of %d \n",x);
    newNode->right = createTree();

    return newNode;
}

void preorder(struct node *root){
    if(root == NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node * root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node * root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}



int main(){
    struct node * root = createTree();

    // preorder //
    preorder(root);

    printf("\n");

    // inorder //
    inorder(root);
    
    printf("\n");

    // postorder //
    postorder(root);

    printf("\n");

    return 0;
}
