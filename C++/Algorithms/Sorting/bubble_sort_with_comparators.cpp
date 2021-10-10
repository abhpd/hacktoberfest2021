#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b){
	
	return a>b;
}

void bubble_sort(int a[],int n,bool (&cmp)(int a,int b)){
	for(int itr=1;itr<n-1 ;itr++){
		for(int j=0 ; j<=n-itr-1 ; j++){
			if(cmp(a[j],a[j+1])){
				swap(a[j],a[j+1]);
			}
		}
	}
}
int main(){

int n, a[100];
cin>>n;

for(int i=0;i<n;i++){
	cin>>a[i];
}

bubble_sort(a,n,compare);
for(int i=0 ; i<n ; i++){
	cout<<a[i]<<",";
}

return 0;
}

