/****************************************************************************************
Author		:	Samuel Palma
Career		:	Ingenieria de Sistema
Desciption	:	Convocatoria Septiembre 29 de 2019.
****************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define LETRA 10

typedef struct{
	char name[LETRA];	//__Nombre de la Ruta__
	char motora[LETRA];	//__Locomotora Asociada__
	char cinicio[LETRA];	//__Ciudad de Inicio__
	char cdestino[LETRA];	//__Ciudad de DEstino__
	int nvagones;	//__Numero de vagones a enganchar para transporte y entrega
}Datos;

typedef struct snodo{
	Datos datos;
	struct snodo *next;
}tnodo;

typedef tnodo *Pnodo;
typedef tnodo *Lista;

//---------------------------------------------------------------------------------------
void Menu();
char Opcion();
void SMSbye();
void SMSerror();
void SMSemptylist();
void SMSdatos(Lista);
bool ListaVacia(Lista *);
//***************************************************************************************
void GetData(Pnodo *, int);

//***************************************************************************************
void Entrada(Lista *);
void Add(Lista *);
void Delete(Lista *);
void Pasar(Lista *);
void Status(Lista);

//---------------------------------------------------------------------------------------
main(){
	Lista lista=NULL;
	char opcion;
	
	do{
		Menu();
		opcion=Opcion();
				
		switch(opcion){
			case '1':
				Entrada(&lista);
				Pasar(&lista);
				break;
			case '2':
				Delete(&lista);
				break;
			case '3':
				break;
			case '4':
				break;
			case 's':
			case 'S':
				SMSbye();
				break;
			default:
				SMSerror();
				break;
		}
	}
	while(opcion!='s' && opcion!='S');
	
	return 0;
}

//---------------------------------------------------------------------------------------
void Menu(){
	system("cls");
	printf("\n\t%c        Menu de Red Vial       %c", 186, 186);
	printf("\n\t%c  1. Insertar Datos en la Red  %c", 186, 186);
	printf("\n\t%c  2. Eliminar Datos en la Red  %c", 186, 186);
	printf("\n\t%c  3. Buscar Datos en la Red    %c", 186, 186);
	printf("\n\t%c  4. Mostrar EStado de la Red  %c", 186, 186);
	printf("\n\t%c  S. Salir de la Red Vial      %c", 186, 186);
}

//---------------------------------------------------------------------------------------
char Opcion(){
	char op;
	
	printf("\n\n\t%c  Ingrese una Opcion  %c", 186, 186);
	printf("\n\t\t*: ");
	fflush(stdin);
	scanf(" %c", &op);
	
	return op;
}

//---------------------------------------------------------------------------------------
void SMSbye(){
	system("cls");
	printf("\n\t%c  Hasta Luego  %c", 186, 186);
	system("pause>nul");
}

//---------------------------------------------------------------------------------------
void SMSerror(){
	systen("cls");
	printf("\n\t%c  ERROR, caracter no valido  %c", 186, 186);
	systen("pause>nul");
}

//---------------------------------------------------------------------------------------
void SMSemptylist(){
	system("cls");
	printf("\n\t%c  Lista Vacia  %c", 186, 186);
	system("pause>nul");
}

//---------------------------------------------------------------------------------------
void SMSdatos(Lista list){
	Pnodo elem=list;
	
	printf("\n\t%c  Ingrese Nombre de la Ruta  %c", 186, 186);
	printf("\n\t\t*: %s", elem->datos.name);
	printf("\n\t%c  Ingrese Locomotora Asociada  %c", 186, 186);
	printf("\n\t\t*: %s", elem->datos.motora);
	printf("\n\t%c  Ingrese Ciudad de Inicio  %c", 186, 186);
	printf("\n\t\t*: %s", elem->datos.cinicio);
	printf("\n\t%c  Ingrese Ciudad de Inicio  %c", 186, 186);
	printf("\n\t\t*: %s", elem->datos.cdestino);
	printf("\n\t%c  Ingrese Numero de Vagones a Enganchar para Transporte y Entrega  %c", 186, 186);
	printf("\n\t\t*: %s", elem->datos.nvagones);
}

//---------------------------------------------------------------------------------------
bool ListaVacia(Lista *list){
	return (*list==NULL)? true : false;
}

//---------------------------------------------------------------------------------------
void GetData(Pnodo *nuevo, int temp){
	Pnodo elem=*nuevo;
	system("cls");
	
	switch(temp){
		case 1:
			printf("\n\t%c  Ingrese Nombre de la Ruta  %c", 186, 186);
			printf("\n\t\t*: ");
			scanf(" %[^\n]", &elem->datos.name);
			break;
		case 2:
			printf("\n\t%c  Ingrese Locomotora Asociada  %c", 186, 186);
			printf("\n\t\t*: ");
			scanf(" %[^\n]", &elem->datos.motora);
			break;
		case 3:
			printf("\n\t%c  Ingrese Ciudad de Inicio  %c", 186, 186);
			printf("\n\t\t*: ");
			scanf(" %[^\n]", &elem->datos.cinicio);
			break;
		case 4:
			printf("\n\t%c  Ingrese Ciudad de Destino  %c", 186, 186);
			printf("\n\t\t*: ");
			scanf(" %[^\n]", &elem->datos.cdestino);
			break;
		case 5:
			printf("\n\t%c  Ingrese Numero de Vagones a Enganchar para Transporte y Entrega  %c", 186, 186);
			printf("\n\t\t*: ");
			scanf(" %d", &elem->datos.nvagones);
			break;
		default:
			printf("\n\t%c  ERROR al Evaluar el SMS a Mostrar  %c", 186, 186);
			system("pause>nul");
			exit(1);
			break;
	}
}
 
//---------------------------------------------------------------------------------------
void Entrada(Lista *list){
	int cantidad, i;
	
	system("cls");
	DesignE();	//__Diseño__
	printf("\n\t%c   Ingrese Cantidad de Instrucciones   %c", 186, 186);
	printf("\n\t%c          de Ruta a Registrar          %c", 186 ,186);
	DesignS();
	printf("\n\t\t*: ");
	scanf("%d", &cantidad);
	
	for(i=0;i<cantidad;i++)
		Add(list);
}

//---------------------------------------------------------------------------------------
void Add(Lista *list){
	Pnodo nuevo=NULL;
	nuevo=(Pnodo)malloc(sizeof(tnodo));
	
	if(nuevo!=NULL){
		GetData(&nuevo, 1);
		GetData(&nuevo, 2);
		GetData(&nuevo, 3);
		GetData(&nuevo, 4);
		GetData(&nuevo, 5);
		nuevo->next=NULL;
		
		if(ListaVacia(list)){
			*list=nuevo;
		}
		else{
			Pnodo last=*list;
			
			while(last && last->next!=NULL)
				last=last->next;
			
			last->next=nuevo;
		}
	}
	else{
		system("cls");
		printf("\n\t%c  ERROR al Asignar Memoria  %c", 186, 186);
		system("pause>nul");
	}
}

//---------------------------------------------------------------------------------------
void Delete(Lista *list){
	if(ListaVacia(list))
		SMSemptylist();
	else{
		Pnodo remove=*list, back=NULL;
		char nruta[LETRA];	//Nombre de la Ruta a ELiminar
		bool estado=false;
		
		printf("\n\t%c  Ingrese Nombre de la Ruta de la   %c", 186 ,186);
		printf("\n\t%c    Intruccion que Desea Eliminar   %c", 186 ,186);
		printf("\n\t\t: ");
		scanf(" %[^\n]", &nruta);
		
		do{
			if(remove->datos.name==nruta)
				estado=true;
				
			back=remove;
			remove=remove->next;
		}
		while((remove && remove->next!=NULL) && remove->datos.name!=nruta);
		
		if(estado){
			SMSdatos(remove);
			system("pause>nul");
			
			back->next=remove->next;
			remove->next=NULL;
			free(remove);
		}
		else{
			system("cls");
			printf("\n\t%c  No Existe Ruta en la Red  %c", 186 ,186);
			system("pause>nul");
		}
	}
}

//---------------------------------------------------------------------------------------
//_Pasamos los vagones a su destino
void Pasar(Lista *list){
	Pnodo aux = *list, aux2=NULL;

	do {
		aux = indice;
		indice = indice->next;

		if (aux->datos.name == indice->datos.cdestino) {
			aux2->datos.name = aux->datos.name;
			aux->datos.cdestino = indice->datos.cdestino;
		}

	} while (indice != NULL);
}
//---------------------------------------------------------------------------------------

void Status(Lista list){
	Pnodo indice=list;
	
	system("cls");
	printf("\n\t  Estado de la Red");
	
	while(indice!=NULL){
		SMSdatos(list);
		indice=indice->next;
	}
	
	system("pause>nul");
}
