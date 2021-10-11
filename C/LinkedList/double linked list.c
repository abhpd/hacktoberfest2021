// Lista enlazada doble o lista doblemente enlazada
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int dato;
	struct NODO *next;
	struct NODO *prev;
}NODO;

NODO* CrearNodo(int dato);
void InsertarNodoFinal(NODO** list, int dato);
void ImprimirListaAdelante(NODO* list);  
void EliminarNodoFinal(NODO** list); 
void InsertarNodoInicio(NODO** list, int dato); 
void EliminarNodoInicio(NODO** list);
void FreeLista(NODO** list); 

int main(void){
	NODO *Lista1=NULL;
	ImprimirListaAdelante(Lista1);
	
	InsertarNodoInicio(&Lista1, 10);
	InsertarNodoInicio(&Lista1, 20);
	InsertarNodoInicio(&Lista1, 30);
	printf("Paso 1: ");
	ImprimirListaAdelante(Lista1);
	printf("\n");
	
	EliminarNodoInicio(&Lista1);
	InsertarNodoFinal(&Lista1, 100);
	InsertarNodoFinal(&Lista1, 120);
	InsertarNodoFinal(&Lista1, 130);
	printf("Paso 2: ");
	ImprimirListaAdelante(Lista1);
	printf("\n");
	
	EliminarNodoFinal(&Lista1);
	EliminarNodoFinal(&Lista1);
	printf("Paso 3: ");
	ImprimirListaAdelante(Lista1);
	printf("\n");
	
	EliminarNodoInicio(&Lista1);
	EliminarNodoInicio(&Lista1);
	EliminarNodoFinal(&Lista1);
	printf("Paso 4: ");
	ImprimirListaAdelante(Lista1);
	
	printf("\n");
	FreeLista(&Lista1);
	printf("\n");
	return 0;
}

void FreeLista(NODO** list){
	NODO *Siguiente=NULL;
	NODO *actual;
	actual = *list;
	while(actual!=NULL){
		Siguiente = actual->next;
		free(actual);
		actual = Siguiente;
	}
	free(Siguiente);
}

void EliminarNodoFinal(NODO** list){
	NODO *penultimo=NULL, *ultimo;
    if(*list==NULL)
        printf("\nNo se puede eliminar NODO, lista vacia\n");
    else{
        ultimo = *list;
        while(ultimo->next!=NULL){
            penultimo = ultimo;
            ultimo = ultimo->next;
        }
        if(penultimo == NULL){
            *list = NULL;
            free(ultimo);
        }else
        {
            penultimo->next = NULL;
            ultimo->prev = NULL;
            free(ultimo);
        }
    }
}

void EliminarNodoInicio(NODO** list){
	NODO *aux;
	if(*list==NULL)
		printf("\nNo se puede eliminar NODO, lista vacia\n");
	else{
		aux = *list;
		*list = aux->next;
		aux->prev = NULL;
		(*list)->prev = NULL;
		free(aux);
	}
}

void ImprimirListaAdelante(NODO* list){
	NODO* aux;
	if(list==NULL){
		printf("\nLista Vacia\n");
	}
	else{
		aux=list;
		do{
			printf("%i  ", aux->dato);
			aux = aux->next;
		}while(aux !=NULL);
	}
}

void InsertarNodoFinal(NODO** list, int dato){
	NODO* NewNodo;
	NODO* ultimo;
	NewNodo=CrearNodo(dato);
	// Verificar si la lista esta vacia
	if(*list == NULL)
		*list=NewNodo;
	else{
		//Si la lista no esta vacia, buscar el nodo final
		ultimo = *list;
		while(ultimo->next != NULL)
			ultimo = ultimo->next;
		//Al final del ciclo while anterior aux contiene 
		//la direccion del ultimo NODO
		ultimo->next=NewNodo;
		NewNodo->prev = ultimo;
	}
}

void InsertarNodoInicio(NODO** list, int dato){
	NODO* NewNodo, *aux;
	aux = *list;
	NewNodo=CrearNodo(dato);
	// Verificar si la lista esta vacia
	if(*list == NULL)
		*list=NewNodo;
	else{
		//Si la lista no esta vacia, insertar nodo al inicio
		(*list)->prev = NewNodo;
		*list=NewNodo;
		NewNodo->next = aux;
	}
}

NODO* CrearNodo(int dato){
	NODO *ptr;
	ptr = (NODO*) malloc(sizeof(NODO));
	ptr->dato = dato;
	ptr->next = NULL;
	ptr->prev = NULL;
	return ptr;
}