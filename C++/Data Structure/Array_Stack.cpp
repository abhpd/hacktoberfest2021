#include <iostream>
#include <iomanip>
using namespace std;

const int size = 10;

template <class T>
class stacktype{
	T s[size];
	int top;
public :
	void push(T);
	T pop();
	int isempty();
	int isfull();
	void display();
	T topmost();
	void clear();
	
	stacktype()
	{
		top = -1;
	}
};

template <class T>
void stacktype<T>::push(T p)
{
	top++;
	s[top] = p;
}

template <class T>
T stacktype<T>::pop()
{
	int d;
	d = s[top];
	top--;
	return d;
}

template <class T>
int stacktype<T>::isempty()
{
	int e;
	if(top == -1)
	{
		cout<<"\nStack is empty"<<endl;
		return 1;
	}
	else
	{
		cout<<"\nStack is not empty"<<endl;
		return 0;
	}
}

template <class T>
int stacktype<T>::isfull()
{
	int f;
	if(top == size-1)
	{
		cout<<"\nStack is full"<<endl;
		return 1;
	}
	else
	{
		cout<<"\nStack is not full"<<endl;
		return 0;
	}
}

template <class T>
T stacktype<T>::topmost()
{
	return s[top];                   
}

template <class T>
void stacktype<T>::clear()
{
	top = -1;          
	display();
}

template <class T>
void stacktype<T>::display()
{
	if(top == -1)
	{
		cout<<"\nStack is empty"<<endl;
	}
	else
	{
		cout<<"\nStack elements starting from top are - ";
		for(int i=top;i>=0;i--)
		{
			cout<<setw(3)<<s[i];
		}
		cout<<endl;
	}
	
}

int main()
{
	stacktype<int> st;
	char c = 'y';
	int choice,f,p,d,e;
	
	while(c=='y'||c=='Y')
	{
		cout<<"MAIN MENU :"<<endl;
		cout<<"From the following options which operation you want to perform on stack :"<<endl;
		cout<<"1. PUSH onto the stack "<<endl;
		cout<<"2. POP from the stack "<<endl;
		cout<<"3. Check if stack is EMPTY "<<endl;
		cout<<"4. Check if stack is FULL "<<endl;
		cout<<"5. CLEAR the stack "<<endl;
		cout<<"6. TOPMOST element of stack "<<endl;
		cout<<"7. DISPLAY the stack "<<endl;
		cout<<"Enter your Choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				f = st.isfull();
			    if(f==1)              //f==1 implies stack is full        
			    {
			    	cout<<endl;
			        cout<<"Insertion of a new element is not possible"<<endl;      //overflow condition
			    }
			    else
			    {
				    cout<<"Enter the element you want to push- ";
				    cin>>p;
				    st.push(p);
				    st.display();
			    }
			    break;
			
			
			case 2:
				e = st.isempty();
				if(e==1)              //e==1 implies stack is empty
				{
					cout<<endl;
					cout<<"Deletion not possible"<<endl;             //Underflow condition
				}
				else
				{
					d = st.pop();
					cout<<"\n"<<d<<" has been deleted";
					st.display();
				}
				break;
				
			case 3:
				e = st.isempty();
				if(e==1)
				{
					cout<<endl;
				}
				else
				{
					cout<<endl;
					st.display();
				}
				break;
				
			case 4:
				f = st.isfull();
				if(f==1)
				{
					cout<<endl;
					st.display();
				}
				else
				{
					cout<<endl;
				}
				break;
				
			case 5:
				st.clear();
				cout<<"\nStack is cleared!!"<<endl;
				break;
				
			case 6:
				e = st.isempty();
				if(e == 1)
				{
					cout<<endl;
				}
				else
				{
					cout<<"The topmost element of the stack is - ";
				    cout<<st.topmost()<<endl;
				}
				/*cout<<"The topmost element of the stack is - ";
				cout<<st.topmost()<<endl;*/
				break;
				
			case 7:
				st.display();
				break;
				
		    default:
		    	cout<<"Invalid Choice!!"<<endl;
		    	break;
		}
		
		cout<<"\nDo you want to continue ??(Y/N): ";
		cin>>c;
	}
	return 0;
}
