//En este caso veremos la cola, en donde el primero que entra es el primero que sale
//Podemos tener un arreglo llamado "fila circular". Donde el incio es el fin.
//Podemos tener una lista que tambien puede ser de prioridades.

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int *data;
	unsigned int Id_Front;
	unsigned int Id_End;
	unsigned int Size;
}FILA;

//PROTOTIPOS
FILA* CrearFila( int Tam); 		//
char Enqueue(FILA *p, int *dato); //		
char Dequeue(FILA *p, int *dato);	//	
char FrontofQueue(FILA *p, int *dato); //
char IsEmpty(FILA *p); 				//	
char IsFull(FILA *p);  				//	
void FreeFila(FILA *p);				//
void MostrarFila(FILA *p);			//	
unsigned int SizeofQueue(FILA *p);	//	
int menu(FILA *fila1);			//		
int Inicio();					//

int main(){
	int TAM, dec=1;
	FILA *fila1;
	TAM=Inicio();
	fila1=CrearFila(TAM);
	while(dec)
		dec=menu(fila1);
	FreeFila(fila1);
	return 0;
}

int Inicio(){
	int TAM;
	system("cls");
	do{
		printf("Tamanio de la fila: ");
		scanf("%d", &TAM); fflush(stdin); 
	}while(TAM<=0); 
	return TAM;
}

int menu(FILA *fila1){
	int valor, op; 
	unsigned int size;
	size=SizeofQueue(fila1);
	
	printf("Hay %u elementos activos de [%u].\n", size, fila1->Size);
	printf("\n1. Ingresar dato en fila.");
	printf("\n2. Eliminar dato en fila.");
	printf("\n3. Mostrar fila.");
	printf("\nOpcion: "); 
	scanf("%d", &op); fflush(stdin);
	switch(op){
		case 1:
			printf("\nValor a ingresar en fila: ");
			scanf("%d", &valor); fflush(stdin);
			if(!Enqueue(fila1, &valor))
				printf("\nEl valor [%i] no ingresado, fila llena. \n", valor);
			else
				printf("\nEl dato [%i] fue ingresado. \n", valor);
			break;	
		case 2:
			if(!Dequeue(fila1, &valor))
				printf("\nDato no sacado, fila vacia. \n", valor);
			else
				printf("\nEl dato [%i] fue sacado. \n", valor);
			break;		
		case 3:
			printf("\nLa fila es: \n");
			MostrarFila(fila1);
			break;
	}
	printf("\nContinuar  [1]");
	printf("\nSalir      [0]");
	printf("\nOpcion: ");
	scanf("%d", &op); fflush(stdin);
	system("cls");
	return op;
}

FILA* CrearFila(int Tam){
	FILA *ptr;
	
	//Asginamos memoria a nuestro apuntador para almacenar la fila
	ptr=(FILA *)malloc(sizeof(FILA)); 
	
	//Verifiacamos si se asignó la memoria correctamente
	if (ptr==NULL){
		printf("Error: Fallo en asignación de memoria. \n");
		exit(0);
	}
	ptr->Id_Front=0;
	ptr->Id_End=0;
	ptr->Size=Tam;
	ptr->data=(int*)malloc(Tam*sizeof(int));
	
	//Verificamos si se reservo memoria correctamente dirigida a data
	if(ptr->data==NULL){
		printf("Error: Fallo en asignación de memoria. \n");
		exit(0);
	}
	printf("\n");
	return ptr;
}

//Función Enqueue
char Enqueue(FILA *p, int *dato){
	//Si no esta llena la FILA
	if(!IsFull(p)){
		//Manejar las direcciones de dato y asignarlo en la direccion data
		*(p->data + p->Id_End)=*dato;
		p->Id_End++;
		return 1;
	}
	else
		//No se pudo ingresar el dato
		return 0;
}


//Función isFull
char IsFull(FILA *p){
	//Verificar si la FILA no está llena
	if(p->Id_End==p->Size)
		return 1;
	else
		return 0;
}

//Función Dequeue
char Dequeue(FILA *p, int *dato){
	if(!IsEmpty(p)){
		*dato=*(p->data + p->Id_Front);
		p->Size++;
		p->Id_Front++;
		return 1;
	}
	else
		return 0;
}

//Función IsEmpty
char IsEmpty(FILA *p){
	//Verificar si la fila esta vacía
	
	if(p->Id_Front == p->Id_End)
		return 1;
	else
		return 0;
}

//Función FrontofQueue
char FrontofQueue(FILA *p, int *dato){
	*dato=*(p->data + p->Id_Front);
}

//Función freeFila
void FreeFila(FILA *p){
	//Liberamos memoria de data y fila
	free(p->data);
	free(p);
}

//Función SizeofQueue
unsigned int SizeofQueue(FILA *p){
	unsigned int size;
	
	//Restar el tamaño de la FILA
	size=(p->Id_End - p->Id_Front);
	return size;
}

//Función mostrarFila
void MostrarFila(FILA *p){
	int i;
	if(IsEmpty(p))
		printf("\nLa fila esta vacia. ");
	else
		//Comenzamos a imprimir el ultimo elemento
		for(i=p->Id_Front; i<(int)p->Id_End; i++)
			printf("%i ", *(p->data+i));
	printf("\n");
}