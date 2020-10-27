#include<iostream>
#define MAX 5

using namespace std;

int stack[MAX];
int top = -1;
int elem;

void pushStack(int elemtemp){
	
	if(top == MAX-1){
		cout<<"\n!!Stack Overflow!!\n";
		return;
	}
	
	else{
		cout<<"\n----Element Stacked Succesfully----\n";
		top += 1;
		stack[top] = elemtemp;
	}
}

int popStack(){
	
	if(top == -1){
		cout<<"\n!!Stack Empty!!\n";
	}
	
	else{
		elem = stack[top];
		top -= 1;
		return elem;
	}
}

void palindrome(){
	
	int check=1,i;
	cout<<"\n\nStack Elements Are : \n";
	
	for(i = top; i >= 0 ; i--){
		cout<<"Index ["<<i<<"] : "<<stack[i]<<"\n";
	}
	
	cout<<"\n\nReversed Stack Elements Are : \n";
	
	for(i = 0; i <= top; i++){
		cout<<"Index ["<<i<<"] : "<<stack[i]<<"\n";
	}
	
	for(i = 0; i <= top/2; i++){
		if(stack[i] != stack[top-i]){
			check = 0;
			break;
		}
	}
	
	if(check == 1){
		printf("\n-------No.s In Stack Are Palindrome-----------");
	}
	
	else{
		printf("\n-------No.s In Stack Are Not Palindrome-------");
	}
}

void displayStack(){

	if(top == -1){
		cout<<"\n!!Stack Empty!!\n";
	}
	
	else{
		cout<<"\n\nStack Elements Are : \n";
		cout<<"\n--------------------------\n";
		for(int i = top; i >= 0; i--){
			cout<<"Index ["<<i<<"] : "<<stack[i]<<"\n";
		}
		cout<<"--------------------------\n";
	}	
}

int main(){
	
	int ch;
	do{
		cout<<"\n\n1.Push An Element In Stack";
		cout<<"\n2.Pop An Element From Stack";
		cout<<"\n3.Palindrome Demonstration";
		cout<<"\n4.Display Elements In Stack";
		cout<<"\n5.Exit";
		cout<<"\n\nEnter Your Choice : ";
		cin>>ch;
		switch(ch){	
			case 1:
				cout<<"Enter The Element To Be Inserted In The Stack :";
				cin>>elem;
				pushStack(elem);
				break;

			case 2:
				elem = popStack();
				if( elem != -1 && top != -1){
					cout<<"\n----Element Popped Succesfully----\n";
					cout<<"Element Popped is : "<<elem;
				}
				break;

			case 3:
				palindrome();
				break;

			case 4:
				displayStack();
				break;

			case 5:
				break;

			default:
				cout<<"Please Enter A Valid Choice";
		}
	}while(ch != 5);

	return 0;
}
