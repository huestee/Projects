/******************************************************************************
Author		:	Samuel Palma
Career		:	Ingenieria de Sistemas
Copyright	:	Todos los derechos reservados ©2019.
Descripcion	:	->	PRUEBA FINAL
******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct sword{	
	char palabra;
	struct sword *next;
}tword;
 
typedef tword *pword;
typedef tword *Word;
 
typedef struct snodo{
	char nombre;
	struct snodo *next;
}tnodo;

typedef tnodo *pnodo;
typedef tnodo *Lista;

//-------------------------------------------------------------------------------
void Menu();		//__Menu Principal__
void MenuJuego();	//__Menu del Juego__
char Opcion();		//__Opcion a Ingresar__
void SMSbye();		//__SMS de Despedida__
void SMSerror();	//__SMS de ERROR__
bool LwordVacia(Word);
bool ListaVacia(Lista);	//__Verifica si la Lista esta Vacia__
//*******************************************************************************
char GetDato(int);	//__Conseguir Nombre del Participante o Palabra de la Oracion__
void CantPerson();	//Consigue el numero de personas a participar en el juego__
void Add(Lista *, char);	//__Añade las personas a la lista__
//*******************************************************************************

//-------------------------------------------------------------------------------
main(){
	Word word=NULL;
	Lista lista=NULL;
	char opcion;
	int dato;
	
	do{
		Menu();
		opcion=Opcion();
		
		system("cls");
		switch(opcion){
			case '1':
				CantPerson(lista);
				break;
			case '2':
				do{
					MenuJuego();
					opcion=Opcion();
					
					system("cls");
					switch(opcion){
						case 'a':
						case 'A':
							dato=GetDato(2);
							AddWord(word, dato);
							break;
						case 'b':
						case 'B':
							break;
						case 'c':
						case 'C':
							break;
						case 'z':
						case 'Z':
							system("cls");
							break;
						default:
							SMSerror();
						break;
					}
				}
				while(opcion!='z' && opcion!='Z');
				
				break;
			case '3':
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
	while(opcion!='S' && opcion!='s');
	
	return 0;
}

/*********************************************************************************
**********************************************************************************
-----------------------------------Menu Principal-------------------------------*/
void Menu(){
	system("cls");
	printf("\n\t *****************************************");
	printf("\n\t%c               Menu Principal            %c", 186, 186);
	printf("\n\t%c              .______________.           %c", 186, 186);
	printf("\n\t%c  1. Ingrese Datos de los Participantes  %c", 186, 186);
	printf("\n\t%c  2. Comenzar a Jugar                    %c", 186, 186);
	printf("\n\t%c  S. Salir del Juego                     %c", 186, 186);
	printf("\n\t%c              .______________.           %c", 186, 186);
	printf("\n\t *****************************************");
}

//-----------------------------------Menu del Juego---------------------------------
void MenuJuego(){
	system("cls");
	printf("\n\t ***************************************************");
	printf("\n\t%c             Menu del Juego de la Oraion           %c", 186, 186);
	printf("\n\t%c                  ._____________.                  %c", 186, 186);
	printf("\n\t%c  A. Ingrese una Palabra a Agregar en la Oracion.  %c", 186, 186);
	printf("\n\t%c                           %c", 186, 186);
	printf("\n\t%c  B. Mostrar el Estado Actual de la Oracion        %c", 186, 186);
	printf("\n\t%c  C. Salir del Juego                     %c", 186, 186);
	printf("\n\t%c    %c", 186, 186);
	printf("\n\t%c    %c", 186, 186);
	printf("\n\t%c    %c", 186, 186);
	printf("\n\t%c    %c", 186, 186);
	printf("\n\t%c    %c", 186, 186);
	printf("\n\t%c    %c", 186, 186);
	printf("\n\t%c    %c", 186, 186);
}

//---------------------------------Opcion------------------------------------------
char Opcion(){
	char op;
	
	printf("\n\n\n");
	printf("\t\t ***********************\n");
	printf("\t\t%c   Ingrese una Opcion  %c\n", 186, 186);
	printf("\t\t ***********************");
	printf("\n\n\t\t*: ");
	fflush(stdin);
	scanf("%c", &op);
	
	return op;
}


//--------------------------------SMS de Error----------------------------------
void SMSerror(){
	printf("\n\n");
	printf("\t\t *****************************");
	printf("\n\t\t%c  ERROR, caracter no valido  %c", 186, 186);
	printf("\n\t\t *****************************");
	system("pause>nul");
}

//------------------------------SMS de Despedida--------------------------------
void SMSbye(){
	system("cls");
	printf("\n\n");
	printf("\t\t **********************");
	printf("\n\t\t%c   Hasta Luego    %c   %c", 186, 2, 186);
	printf("\n\t\t **********************");
	system("pause>nul");
}

//--------------------------------Lista Vacia---------------------------------------
bool ListaVacia(Lista list){
	if(list==NULL)
		return true;
	else
		return false;
}

//--------------------------------Lista Vacia---------------------------------------
bool LwordVacia(Word lword){
	if(lword==NULL)
		return true;
	else
		return false;
}

/***********************************************************************************
************************************************************************************
----------------------------------Conseguir datos---------------------------------*/
char GetDato(int temp){
	char *dato;
	
	if(temp==1){
		printf(" ***********************************************");
		printf("\n\t%c      Ingrese Nombre del Participante      %c", 186, 186);
		printf(" ***********************************************");
		printf("\n\t\t*: ");
		fflush(stdin);
		scanf(" %[^\n]", &dato);
		
		return *dato;
	}
	else if(temp==2){
		printf(" ***********************************************");
		printf("\n\t%c  Ingrese Palabra a Agregar en la Oracion  %c", 186, 186);
		printf(" ***********************************************");
		printf("\n\t\t*: ");
		fflush(stdin);
		scanf(" %[^\n]", &dato);
	}
	else{
		printf(" ****************************************************");
		printf("\n\t%c  ERROR al momento de Indicar el SMS a Mostrar  %c", 186, 186);
		printf(" ****************************************************");
		system("pause>nul");
	}
		
	return *dato;
}

//--------------------------Cantidad de Personas a Participar-----------------------
void CantPerson(Lista list){
	int cant, i;
	
	system("cls");
	printf("\n\t *********************************************");
	printf("\n\t%c  Ingrese Cantidad de Personas a Participar  %c", 186, 186);
	printf("\n\t *********************************************");
	printf("\n\t\t*: ");
	scanf("%d", &cant);
	
	for(i=0;i<cant;i++){
		Add(&list, GetDato(1));
	}
}

void Add(Lista *list, char dato){
	pnodo nuevo=NULL;
	nuevo=(pnodo)malloc(sizeof(tnodo));
	
	if(nuevo!=NULL){
		nuevo->nombre=dato;
		nuevo->next=NULL;
		
		if(ListaVacia)	//__Se agrega cuando la lista esta vacia__
			*list=nuevo;	//__Se agrega primer participante__
		else{	//__Se agrega cuando la lista ya tiene elementos__
			pnodo ultimo=NULL;
			
			while(ultimo!=NULL)
				ultimo=ultimo->next;
				
			ultimo->next=nuevo;	//__Se agrega participante despues de otro__
		}
	}
}

void AddWord(Word *lword, char dato){
	pword nuevo=NULL;
	nuevo=(pword)malloc(sizeof(tword));
	
	if(nuevo!=NULL){
		nuevo->palabra=dato;
		nuevo->next=NULL;
		
		if(LwordVacia)	//__Se agrega cuando la lista esta vacia__
			*lword=nuevo;	//__Se agrega primer participante__
		else{	//__Se agrega cuando la lista ya tiene elementos__
			pword ultimo=NULL;
			
			while(ultimo!=NULL)
				ultimo=ultimo->next;
				
			ultimo->next=nuevo;	//__Se agrega participante despues de otro__
		}
	}
}


















