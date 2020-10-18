/* Remove space in the input string , Input is in form- Firts line : Number of Test Cases
                                                       Second line : String for each test case */

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
    {
        string s,sh;
        int j=0;
        cin>>s;
        for(int i=0;s[i]!=NULL;i++)
        {
            if(s[i]!=' ')
            {
             sh[j]=s[i];
             j++;
            }
        }
        sh[j]=NULL;
        cout<<sh<<endl;

    }
	return 0;
}
