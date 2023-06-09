#include<iostream>

using namespace std;
class ajay
{
	int a;
	public:
	ajay()
	{
		a=10;
	}
	ajay operator++()
	{
		ajay t;
		t.a=++a;
		return t;
	}
	void show()
	{
		cout<<"value-"<<a<<endl;
	}
};
int main()
{
	ajay a1;
	a1.show();
	ajay a2=++a1;	
}
