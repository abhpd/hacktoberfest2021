#include<stdio.h>

main(){
	float a;
	int b, c=0;
	for(b=0; b<=5; b++){
		printf("Digite um numero:\n");
		scanf("%f", &a);
		if(a>=10 && a<=150){
			c++;
		}
	}
	printf("Existem %d numeros entre 10 e 150.", c);
}
