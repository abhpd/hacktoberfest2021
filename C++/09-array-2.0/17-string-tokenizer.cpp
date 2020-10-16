#include<iostream>
#include <cstring>
using namespace std;


int main(){
	char para[]= "Hello my name is md!Who are you?:)";
	char deliminator[] = " ?!";
	char *s = strtok(para, deliminator); // contanis static variable which store status in previous call.
	
	while(s!=NULL){
		cout<<s<<endl;
		s = strtok(NULL, deliminator);
	}
	return 0;
}

/*

strtok => string tokenizer function.
token=> delimiter, can me more than one.
char * strtok(char* str, char * delemiters);
Note: in subsequent call str should me null

*/