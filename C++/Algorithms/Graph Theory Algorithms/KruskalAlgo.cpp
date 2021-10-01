 #include <bits/stdc++.h>
using namespace std;
void make_set(vector<int>&parent){
    for(int i=0;i<parent.size();i++){
        parent[i]=i;
    }
}
int find(vector<int>&parent,int r1){
    if(parent[r1]!=r1){
        parent[r1]=find(parent,parent[parent[r1]]);
    }
    return parent[r1];
}
void union_set(vector<int>&parent,vector<int>&rank,int q,int r){
    int root1=find(parent,q);
    int root2=find(parent,r);
    if(root1==root2)
    return;
    if(rank[root1]>rank[root2]){
        parent[root2]=root1;
    }
    else{
        parent[root1]=root2;
        rank[root2]++;
    }
}
bool compare(const tuple<int,int,int>&a ,const tuple<int,int,int>&b){
    return get<2>(a)<get<2>(b);
}
vector<tuple<int,int,int>>kruskal(vector<tuple<int,int,int>>&minh,int size){
    vector<tuple<int,int,int>>res;
    sort(minh.begin(),minh.end(),compare);
    vector<int>parent(size);
    vector<int>rank(size,0);
    make_set(parent);
    for(tuple<int,int,int>x:minh){
        int weight= get<2>(x);
        int q=get<0>(x);;
        int r=get<1>(x);;
       
        if(find(parent,q)!=find(parent,r)){
             res.push_back(make_tuple(q,r,weight));
             union_set(parent,rank,q,r);
        }
    }
    return res;
}
int main()
{
    int size = 7;
    vector<tuple<int,int,int>>minh;
    minh.push_back(make_tuple(0, 1,2));
    minh.push_back(make_tuple(0, 3,7));
    minh.push_back(make_tuple(0, 5,2));
    minh.push_back(make_tuple(1, 2,1));
    minh.push_back(make_tuple(1, 3,4));
    minh.push_back(make_tuple(1, 4,3));
    minh.push_back(make_tuple(1, 5,5));
    minh.push_back(make_tuple(2, 4,4));
    minh.push_back(make_tuple(2, 5,4));
    minh.push_back(make_tuple(3, 4,1));
    minh.push_back(make_tuple(3, 6,5));
    minh.push_back(make_tuple(4, 6,7));
    vector<tuple<int,int,int>>v1=kruskal(minh,size);
    for(tuple<int,int,int>x:v1){
        cout<<get<0>(x)<<"->"<<get<1>(x)<<","<<get<2>(x)<<endl;
    }

    return 0;
}