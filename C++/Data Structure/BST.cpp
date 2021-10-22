#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
//------------Node Class
class node{
public:
	int data;
	node* left;
	node* right;


	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

//------------Binary Search Tree 

node* insertInBst(node*root,int d){
	if(root==NULL){
		return new node(d);
	}
	//Rec Case
	if(d<root->data){
		root->left = insertInBst(root->left,d);
	}
	else{
		root->right = insertInBst(root->right,d);
	}
	return root;
}

bool search(node*root, int key){

	//Base Case
	if(root==NULL){
		return false;
	}
	if(root->data==key){
		return true;
	}
	if(key<root->data){
		return search(root->left,key);
	}
	return search(root->right,key);
}
node* deleteFromBST(node*root,int key){
	if(root==NULL){
		//key doesnt exist
		return root;
	}
	if(key<root->data){
		// search in left subtree
		root->left = deleteFromBST(root->left,key);
		return root;
	}
	else if(key>root->data){
		// search in right subtree
		root->right =  deleteFromBST(root->right,key);
		return root;
	}
	else{
		//Key==root->data, key mil gyi!
		if(key==root->data){
			//0 children
			if(root->left==NULL && root->right==NULL){
				delete root;
				return NULL;
			}
			//1 child
			else if(root->left==NULL && root->right!=NULL){
				node*temp = root->right;
				delete root;
				return temp;
			}

			else if(root->left!=NULL && root->right==NULL){
				node*temp = root->left;
				delete root;
				return temp;
			}

			//2 children

			else{
				node* nextBig = root->right;
				
				while(nextBig->left!=NULL){
					nextBig = nextBig->left;
				}
				root->data = nextBig->data;

				root->right = deleteFromBST(root->right,root->data);
				return root;
				
			}
		}

	}
}



node* buildFromArray(int a[],int s,int e){
	if(s>e){
		return NULL;
	}

	int mid = (s+e)/2;

	node*root = new node(a[mid]);
	root->left = buildFromArray(a,s,mid-1);
	root->right = buildFromArray(a,mid+1,e);
	return root;
}


 node *buildBST(){
 	//Read the inp
 	int d;
 	cin>>d;
 	node*root = NULL;
 	while(d!=-1){
 		root = insertInBst(root,d);
 		cin>>d;
 	}
 	return root;
 }

void printPre(node *root){
		if(root==NULL){
			return;
		}
		cout<<root->data<<" ";
		printPre(root->left);
		printPre(root->right);
}
void printIn(node *root){
		if(root==NULL){
			return;
		}
		
		printIn(root->left);
		cout<<root->data<<" ";
		printIn(root->right);
}
void printPost(node *root){
		if(root==NULL){
			return;
		}
		
		printPost(root->left);
		printPost(root->right);
		cout<<root->data<<" ";
}
void printLevelOrder(node*root){

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* f = q.front();

		if(f==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}

		else{
			cout<<f->data<<" ";
			q.pop();
			if(f->left){
				q.push(f->left);
			}
			if(f->right){
				q.push(f->right);
			}
		}

	}

}


class Pair{
public:
	node*head;
	node*tail;
};

Pair flattenLL(node*root){
	Pair p;
	if(root==NULL){
		p.head = p.tail = NULL;
		return p;
	}
	if(root->left==NULL && root->right==NULL){
		p.head = p.tail = root;
		return p;
	}
	else if(root->left!=NULL && root->right==NULL){
		Pair leftLL = flattenLL(root->left);
		leftLL.tail->right = root;
		p.head = leftLL.head;
		p.tail  = root;
		return p;
	}

	else if(root->right!=NULL && root->left==NULL){
		Pair rightLL = flattenLL(root->right);
		root->right = rightLL.head;
		p.head = root;
		p.tail = rightLL.tail;
		return p;
	}
	else{
		Pair leftLL = flattenLL(root->left);
		Pair rightLL = flattenLL(root->right);
		leftLL.tail->right = root;
		root->right = rightLL.head;
		p.head = leftLL.head;
		p.tail = rightLL.tail;
		return p;
	}

}


int main(){
	node*root = buildBST(); // buildFromArray(a,s,e);

	/*cout<<"Enter Node to Delete";
	int key;
	cin>>key;
	//root  = deleteFromBST(root,key);
	printPre(root);
	cout<<endl;
	printIn(root);
	cout<<endl;
	printPost(root);
	cout<<endl;
	printLevelOrder(root);*/

	Pair linkedList = flattenLL(root);
	node* temp = linkedList.head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->right;
	}
	

	return 0;
}

/* 

8
10
1
-1
-1
6
9
-1
-1
7
-1
-1
3
-1
14
13
-1
-1
-1


*/