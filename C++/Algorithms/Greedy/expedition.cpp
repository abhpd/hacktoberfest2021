#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.first<p2.first;
}
int main(){
    int d,p;
    cin>>d>>p;
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int dis,f;
        v.push_back(make_pair(d-dis,f));
    }
    sort(v.begin(),v.end(),compare);
    int ans=0;
    priority_queue<int> q;
    int prev=0;
    for(int i=0;i<n;i++){
        if(p>=v[i].first-prev){
            p-=(v[i].first-prev);
            q.push(v[i].second);
            prev=v[i].first;
        }else{
            p+=q.top();
            q.pop();
            ans++;
            continue;
        }
    }
    


    cout<<ans<<endl;

}

