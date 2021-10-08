#include<iostream>
#include<string.h>
using namespace std;
class laptop
{ 
    protected:
	float price;
	
	
	public:
	void get_data()
	{
		cin>>price;
		cout<<price<<endl;
		
	}
	friend void start_up(laptop l)
	{
		cout<<l.price<<endl;	
	}
	void shut_down()
	{
		
		cout<<"laptop is shutting down";
	}
};
int main()
{
laptop laptop1;
laptop1.get_data();	
start_up(laptop1);
return 0;
}
