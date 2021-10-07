#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#define type_name(expr) (_Generic((expr), char: "char", unsigned char: "unsigned char", signed char: "signed char", short: "short", unsigned short: "unsigned short", int: "int", unsigned int: "unsigned int", long: "long", unsigned long: "unsigned long", long long: "long long", unsigned long long: "unsigned long long", float: "float", double: "double", long double: "long double", void*: "void*", char*: "String", default: "?")) 
#define STACK_MAX 401

typedef char String[256];

typedef union {
	int intValue;
	float floatValue;
	char charValue;
	String stringValue;
} UnionData;

typedef struct {
	unsigned int Index;
	String TypeName;
	UnionData Data;
} Item;

bool emptyStack(Item stack[]);

bool fullStack(Item stack[]);

void push(Item stack[], Item value);

Item pop(Item stack[]);

Item* createStack(int size);

void printStack(Item stack[]);

bool emptyStack(Item stack[]) {
	return stack[0].Index == 0;
}

bool fullStack(Item stack[]) {
	return stack[0].Index == STACK_MAX;
}

void push(Item stack[], Item value) {
	
	if(fullStack(stack)) {
		printf(" - The stack is full.\n");
		return;
	}
	
	stack[0].Index += 1;
	
	if(strcmp(value.TypeName, "int") == 0) {
		stack[stack[0].Index].Data.intValue = value.Data.intValue;
	} else if(strcmp(value.TypeName, "float") == 0) {
		stack[stack[0].Index].Data.floatValue = value.Data.floatValue;
	} else if(strcmp(value.TypeName, "char") == 0) {
		stack[stack[0].Index].Data.charValue = value.Data.charValue;
	} else if(strcmp(value.TypeName, "String") == 0) {
		strcpy(stack[stack[0].Index].Data.stringValue, value.Data.stringValue);
	}
	
	
}

Item pop(Item stack[]) {
	stack[0].Index -= 1;
	return stack[stack[0].Index + 1];
}

Item* createStack(int size) {
	
	static Item stack[STACK_MAX];
	int i = 0, choice = 0;
	char ch;
	
	for(i = 0; i < STACK_MAX; i++) {
		stack[i].Index = 0;
	}
	
	if(size != 0) {
		for(i = 1; i <= size; i++) {
			printf("\n");
			printf(" Which type of data do you want to insert?\n");
			printf(" 1. int\n");
			printf(" 2. float\n");
			printf(" 3. char\n");
			printf(" 4. String\n");
			printf("\n Choose a number between 1 and 4 (inclusive), any other number to EXIT ---> ");
			scanf(" %d", &choice);
			
			switch(choice) {
				
				case 1:
					printf(" Insert Integer Value #%d: ", i);
					strcpy(stack[i].TypeName, type_name(stack[i].Data.intValue));
					scanf(" %d", &stack[i].Data.intValue);
					break;
				case 2:
					printf(" Insert Floating-Point Value #%d: ", i);
					strcpy(stack[i].TypeName, type_name(stack[i].Data.floatValue));
					scanf(" %f", &stack[i].Data.floatValue);
					break;
				case 3:
					printf(" Insert Character #%d: ", i);
					strcpy(stack[i].TypeName, type_name(stack[i].Data.charValue));
					scanf(" %c", &stack[i].Data.charValue);
					break;
				case 4:
					printf(" Insert String #%d: ", i);
					strcpy(stack[i].TypeName, type_name(stack[i].Data.stringValue));
					scanf("%s", &stack[i].Data.stringValue);
					break;
				default:
					exit(EXIT_SUCCESS);
					break;
			}
			
			while (((ch = getchar()) != EOF) && (ch != '\n'));
			
			choice = 0;
			
			stack[0].Index++;
		}
	}
	
	return stack;
}

void printStack(Item stack[]) {
	
	int i = 1;
	
	Item tmp;
	
	printf("\n\nStack size: %d\n", stack[0].Index);
	if(!emptyStack(stack)) {
		while(!emptyStack(stack)) {
			tmp = pop(stack);
			if(strcmp(tmp.TypeName, "int") == 0) {
				printf(" - Element #%d: %d\n", i, tmp.Data.intValue);
			} else if(strcmp(tmp.TypeName, "float") == 0) {
				printf(" - Element #%d: %f\n", i, tmp.Data.floatValue);
			} else if(strcmp(tmp.TypeName, "char") == 0) {
				printf(" - Element #%d: %c\n", i, tmp.Data.charValue);
			} else if(strcmp(tmp.TypeName, "String") == 0) {
				printf(" - Element #%d: %s\n", i, tmp.Data.stringValue);
			}
			
			i++;
		}
	} else {
		printf(" - The stack is empty.\n");
	}
	
}

int main(void) {
	
	srand(time(NULL));
	
	int i = 0, choice = 0;
	char ch;
	
	printf("\n Insert stack size (MAX 400): ");
	
	scanf("%d", &choice);
	
	if(choice > 400 || choice < 1) return 0;
	
	Item *stack = createStack(choice);
	
	printStack(stack);
	
	return 0;
}
