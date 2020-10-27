#include <iostream>
using namespace std;
void balanced_bracket(char output[],int n,int open,int close,int j){
    //base case
    if(j==2*n){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
    //rec case
    if(open<n){
        output[j]='(';
        balanced_bracket(output,n,open+1,close,j+1);
    }
    if(close<open){
        output[j]=')';
        balanced_bracket(output,n,open,close+1,j+1);
    }
}
int main(){
  int n;
  cin>>n;
  char output[2*n+1];
  balanced_bracket(output,n,0,0,0);

}
