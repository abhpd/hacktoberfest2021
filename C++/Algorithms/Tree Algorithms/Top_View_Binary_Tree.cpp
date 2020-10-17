#include<iostream>
#include<queue>
#include<map>
using namespace std;

//class node 
class node{
  public:
  int data;
  node*right,*left;

  node(int d){    //constructor
	  data=d;
	  right=left=NULL;
  }
};

//Building tree by Level order input for the binary tree .
node* build(){
    queue<node*> q;
    int d; cin>>d;
    node* root=new node(d);
    q.push(root);
    while(!q.empty()){
        node* stop=q.front();
        q.pop();
        int r,l;
        cin>>l>>r;
        if(l!=-1){
            stop->left=new node(l);
            q.push(stop->left);
        }
        if(r!=-1){
            stop->right=new node(r);
            q.push(stop->right);
        }
        if(r==-1){
            stop->right=NULL;
        }
        if(l==-1){
            stop->left=NULL;
        }
    }
	return root;
}

//Top View using Maps
void top_view(node* root,map<int,vector<int>>& m,int k){
    if(root==NULL) return;
    m[k].push_back(root->data);
    top_view(root->left,m,k-1);
    top_view(root->right,m,k+1);
    return;
}

int main() {
    map<int,vector<int>> m;
	  node*root=build();
    top_view(root,m,0);	
    
    //printing the top view of Binary Tree
    for(auto i:m){
          vector<int> p=i.second;
            cout<<p[0]<<" ";
    }
	return 0;
}
