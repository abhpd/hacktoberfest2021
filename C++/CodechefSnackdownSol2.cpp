#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int input;
	    int India= 0,England = 0;
	    for(int i=0;i<5;i++)
	    {
	        cin>>input;
	        if(input==1)
	        India++;
	        else if(input==2)
	        England++;
	    }
	    if(India==England)
	    cout<<"DRAW"<<endl;
	    else if(India>England)
	    cout<<"INDIA"<<endl;
	    else
	    cout<<"ENGLAND"<<endl;
	}
	return 0;
}
