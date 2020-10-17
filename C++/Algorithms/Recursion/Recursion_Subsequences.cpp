#include<iostream>
#include<string>
using namespace std;

//ans variable contains number of subsequnces of a string 
static long long int ans=0;

//function for printing Subsequences of a string 
void subsequences(char* s,int i,int j,char* out){
   if(s[i]=='\0'){
	   out[j]='\0';
     ans++;
	   cout<<out<<" ";
	   return ;
   }

   subsequences(s,i+1,j,out);
   out[j]=s[i];
   subsequences(s,i+1,j+1,out);

}

int main() {
	char s[10000];
	cin>>s;
  char out[10000];
	subsequences(s,0,0,out);
  cout<<endl<<ans;
	return 0;
}
