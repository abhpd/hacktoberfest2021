#include <stdio.h>
#include <conio.h>

int x[5][5],r[5],c[5];
int i,j,d1,d2,ctr;

void main(){
	//entering value
	for(i=0;i<5;i++)
		for(j=0;j<5;j++){
			printf("Enter a number: ");
			scanf("%d",&j);
		}
		//printing array
	for(i=0;i<5;i++)
		for(j=0;j<5;j++){
			//row sum
			r[i]=r[i] + x[i][j];
			//col sum
			c[i]=c[i] x[j][i];
			//diagonal
			if(i == )
				d1 __ x[i][j];
			if(i+j == )
				d2 __ x[i][j];
		}
		
	for(i=0;i<5;i++)
		if(r[i] == d2 && d1 == d2 && r[i] == d1)
			ctr=ctr+;
		if(ctr == 5)
			printf("It is a Magic Square");
		else
			printf("It is not a magic Square");
}
