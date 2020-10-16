#include<iostream>
#include <cstring>
using namespace std;

char *mystrtok(char str[], char delim){

	static char * input = NULL;
	int i;
	if(str!=NULL){
		input = str; // point to str
	}
	if(input==NULL){
		return input;
	}

	char *output = new char[strlen(input)+1]; // dynamic memory, will not destroy on its own
	// return dynamically allocated array
	// read from input and store to output
	// and return word till deliminator

	for(i=0; input[i]!='\0';i++){
		if(input[i]!=delim){
			//copy to char
			output[i] = input[i];
		}
		else{
			// it is deliminator
			output[i] ='\0';
			input += i+1; // pointer points to next word
			return output;
		}
	}
	// return the last word if delim is not there
	output[i]='\0';
	input=NULL;
	return output;
}

int main(){
	char para[]= "Hello my name is md!Who are you?:)";
	char deliminator = ' ';
	char *s = mystrtok(para, deliminator); // contanis static variable which store status in previous call.
	
	while(s!=NULL){
		cout<<s<<endl;
		s = mystrtok(NULL, deliminator);
	}
	return 0;
}

/*


*/