#include <iostream>
using namespace std;
int main(){
   
        int n;
        cin>>n;
        int a[n];
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        int ans=0;
        int req=sum/n;
        int current=0;
        for(int i=0;i<n;i++){
            current+=a[i];
            int current_ans=abs(current-req*(i+1));
            ans=max(ans,current_ans);
        }
        cout<<ans<<endl;

}