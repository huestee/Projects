/****************************************************************************
Author      :	Samuel Palma
Career      : Ingenieria en Sistemas
Copyright   : Todos los derechos reservados 2019.
Description	: PILA.	Insertar, eliminar datos.	Pila con funciones.
****************************************************************************/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define STACKSIZE 10

//////////////////////////////Estructuras////////////////////////////////////
typedef struct{
	int items[STACKSIZE];	//Valor del Elemento.
	int tope;  	//Elemento Cima de la pila.
}stack;

////////////////////////Prototipos de Funcion////////////////////////////////
void Designmenu1();		//Diseño para el Menu
void Designmenu0();		//Diseño  ||    ||
void Design1();		//Diseño en general
void Design0();		//Diseño	||
void Designresul1();	//Diseño para el estado de la pila
void Designresul0();	//Diseño	||		||		||

void Menu();
void Entrada(stack *);
int Push(stack *);
void Pop(stack *);
void Stacktope(stack );
void Stackstatus(stack );

main(){
	stack p;
	char opcion;
	p.tope=-1;

	do{
		clrscr();

		Menu();
		printf("\n\t*: ");
		fflush(stdin);
		scanf(" %c", &opcion);

		switch(opcion){
		case '1':
			clrscr();

			Entrada(&p);
			getch();
			break;
		case '2':
			clrscr();

			Pop(&p);
			getch();
			break;
		case '3':
			clrscr();

			Stacktope(p);
			getch();
			break;
		case '4':
			clrscr();

			Stackstatus(p);
			getch();
			break;
		case 's':
		case 'S':
			clrscr();

			Designmenu1();		//Diseño
			printf("\n%c            Hasta Luego %c             %c", 186, 2, 186);
			Designmenu0();		//Diseño
			break;
		default:
			clrscr();

			Designmenu1();		//Diseño
			printf("\n%c      Error, caracter no valido       %c", 186, 186);
			Designmenu0();		//Diseño
			getch();
			break;
	}

		fflush(stdin);
	}
	while(opcion!='s' && opcion!='S');

	getch();
	return 0;
}


////////////////////////////////Funciones/////////////////////////////////////


//---------------------------Menu-------------------------
void Menu(){
	Designmenu1();	//Diseño
	printf("\n%c              Menu                    %c", 186, 186);
	printf("\n%c   1. Insertar Elemento               %c", 186, 186);
	printf("\n%c   2. Eliminar Elemento               %c", 186, 186);
	printf("\n%c   3. Mostrar Elemento en la Cima     %c", 186, 186);
	printf("\n%c   4. Mostrar Estado de la Pila       %c", 186, 186);
	printf("\n%c   s. Salir                           %c", 186, 186);
	Designmenu0();	//Diseño
}

//-------------------------------Pusp-----------------------
void Entrada(stack *p){
	int cant, i;
	
	Design1();		//Diseño
	printf("\n%c    Cantidad de Elementos    %c", 186, 186);
	Design0();		//Diseño
	
	printf("\n\n\t*: ");
	scanf("%d", &cant);

	clrscr();

	if(cant>STACKSIZE){
		Design1();		//Diseño
		printf("\n%c         Sobrecarga          %c", 186, 186);
		Design0();		//Diseño
		getch();
	}
	else{
		for(i=0;i<cant;i++){
			clrscr();
			
			Push(p);
		}
	}
}

int Push(stack *p){
	int elem;
	
	if(p->tope==STACKSIZE-1){
		Design1();		//Diseño
		printf("\n%c        Desbordamiento       %c", 186, 186);
		Design0();		//Diseño
	}
	else{
		Design1();		//Diseño
		printf("\n%c       Ingrese un Numero     %c", 186, 186);
		Design0();		//Diseño
		
		printf("\n\t*: ");
		scanf("%d", &elem);

		p->tope+=1;
		p->items[p->tope]=elem;
	}
	return p->tope;
}

//-----------------------------Pop---------------------------
void Pop(stack *p){
	int temp;

	if(p->tope==-1){
		Design1();		//Diseño
		printf("\n%c   Subdesborde en la pila    %c", 186, 186);
		Design0();		//Diseño
	}
	else{
		temp=p->items[p->tope];
		p->tope=p->tope-1;
		
		Design1();		//Diseño
		printf("\n%c     Elemento Eliminado      %c", 186, 186);
		Design0();		//Diseño
		
		printf("\n\t*: %d", temp);
	}
}

//-----------------------Stacktope---------------------------
void Stacktope(stack p){

	if(p.tope==-1){
		Design1();		//Diseño
		printf("\n%c          Pila Vacia         %c", 186, 186);
		Design0();		//Diseño
	}
	else{
		Design1();		//Diseño
		printf("\n%c  Elemento Cima de la Pila   %c", 186, 186);
		Design0();		//Diseño

		printf("\n\t*: %d", p.items[p.tope]);
	}
}

//---------------------Stackstatus--------------------------
void Stackstatus(stack p){
	int i;

	if(p.tope==-1){
		Design1();		//Diseño
		printf("\n%c          Pila Vacia         %c", 186, 186);
		Design0();		//Diseño
	}
	else{
		Designresul1();		//Dise¤o
		for(i=p.tope;i>=0;i--){
			printf("\n%c   [%d]   %c  %c\t*: %d", 186, i, 186, 26, p.items[i]);
			Designresul0();		//Dise¤o
		}
	}
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//---------------------Inicio Diseño del Menu----------------------
void Designmenu1(){
	int d;

	printf("\n%c", 201);
	for(d=0;d<38;d++)
		printf("%c", 205);
	printf("%c", 187);
}

//---------------------Fin Diseño del Menu-------------------------
void Designmenu0(){
	int d;

	printf("\n%c", 200);
	for(d=0;d<38;d++)
		printf("%c", 205);
	printf("%c", 188);
}

//------------------------Inicio Diseño----------------------------
void Design1(){
	int d;

	printf("\n%c", 201);
	for(d=0;d<29;d++)
		printf("%c", 205);
	printf("%c", 187);
}

//---------------------------Fin Diseño---------------------------
void Design0(){
	int d;

	printf("\n%c", 200);
	for(d=0;d<29;d++)
		printf("%c", 205);
	printf("%c", 188);
}

//----------------------Inicio Diseño Resultado-------------------
void Designresul1(){
	int d;
	
	printf("\n%c", 201);
	for(d=0;d<9;d++)
		printf("%c", 205);
	printf("%c", 187);
}
//----------------------Fin Diseño Resultado-----------------------
void Designresul0(){
	int d;
	
	printf("\n%c", 200);
	for(d=0;d<9;d++)
		printf("%c", 205);
	printf("%c", 188);
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

