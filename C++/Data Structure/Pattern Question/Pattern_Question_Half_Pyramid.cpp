#include<iostream>
using namespace std;

int main()
{

int n;
cin>>n;

for(int i=n;i>=1;i--){
    for(int j=1;j<=n+1-i;j++){
        cout<<j<<" ";
    }
    cout<<endl;
}
return 0;
}











  

