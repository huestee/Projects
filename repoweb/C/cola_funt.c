/****************************************************************************
Author				:	Samuel Palma
Career				:	Ingenieria de Sistemas
Description	:	Este ejercicio se basa en una Cola Cirular con su repectivo
							 Reajuste de Cola.
****************************************************************************/
#include<stdio.h>
#include<conio.h>
#define SIZE 10


//------------------------------Estructuras----------------------------------
typedef struct{
	//int items[SIZE];
	int frente, final;
}cola;

typedef struct{
	char nombre[50];
	int id;
}datos;

//-----------------------------Prototipos de funcion-------------------------
void Menu();
void Entrada(cola *, datos *);
void Push(cola *, datos *);
void Pop_Reajuste(cola *, datos *);
void Colafrentefinal(cola, datos);
void Colastatus(cola, datos);

void Design1();	//__________Diseño_____________
void Design0();	//__________Diseño_____________
void Dise1();		//__________Diseño_____________
void Dise0();		//__________Diseño_____________
void Diseno1();	//__________Dise¤o_____________
void Diseno0(); //__________Dise¤o_____________

//---------------------------------Funcion Pricipal--------------------------
main(){
	char opcion;
	int d;
	datos d[SIZE];
	cola c;
	c.frente=0;
	c.final=-1;

	do{
		clrscr();
		Menu();

		printf("\n\n\t*: ");
		fflush(stdin);
		scanf(" %c", &opcion);

		//----------Dise¤o para simular que el programa esta cargando------------
		printf("\n\n\n\tCargando");
		getch();
		for(d=0;d<=3;d++){
			printf(".");
			getch();
		}

		//-----------------------------------------------------------------------
		switch(opcion){
			case '1':
				Entrada(&c, &d);
				break;
			case '2':
				Pop_Reajuste(&c, &d);
				break;
			case '3':
				Colafrentefinal(c);
				break;
			case '4':
				Colastatus(c);
				break;
			case 's':
			case 'S':
				clrscr();

				Design1();	// <-_______Diseño________
				printf("\n%c            Hasta Luego  %c             %c", 186, 2, 186);
				Design0();	// <-_______Diseño________
				break;
			default:
				clrscr();

				Design1();	// <-_______Diseño________
				printf("\n%c        Error, digito no valido        %c", 186, 186);
				Design0();	// <-_______Diseño________
				getch();
				break;
		}
		fflush(stdin);
	}
	while(opcion!='s' && opcion!='S');

	getch();
	return 0;
}

//------------------------------------Menu-----------------------------------
void Menu(){
	Design1();	// <-_______Diseño________
	printf("\n%c                   Menu                %c", 186, 186);
	printf("\n%c                                       %c", 186, 186);
	printf("\n%c  1. Ingrese Elemento                  %c", 186, 186);
	printf("\n%c  2. Retirar Elemento                  %c", 186, 186);
	printf("\n%c  3. Mostrar Elementos Frente y Final  %c", 186, 186);
	printf("\n%c  4. Mostrar Estado de la Cola         %c", 186, 186);
	printf("\n%c  s. Salir                             %c", 186, 186);
	Design0();	// <-_______Diseño________
	printf("\n\n\n----------------------------------------------------");
	printf("\n%c               Eliga una opcion        %c", 186, 186);
	printf("\n\n\n****************************************************");
}

//----------------------------------Entrada----------------------------------
void Entrada(cola *c, datos *d){
	int cant, i;
	clrscr();

	Design1();	// <-_______Diseño_______
	printf("\n%c         Cantidad de Elementos         %c", 186, 186);	//Cantidad de elementos para ingresar
	Design0();	// <-_______Diseño_______

	printf("\n\n\t*: ");
	scanf("%d", &cant);

	if(cant>SIZE){
		clrscr();

		Dise1();	// <-_______Diseño_______
		printf("\n%c     Sobrecarga   %c");
		Dise0();	// <-_______Diseño_______

		getch();
	}
	else
		for(i=0;i<cant;i++)
			Push(c, d);
}

//-----------------------------Encolar - Inserccion--------------------------
void Push(cola *c, datos *d){
	int id;
	char nombre[50];

	clrscr();
	if(c->final==SIZE-1){
		Dise1();	// <-_______Diseño_______
		printf("\n%c  Desbordamiento  %c");
		Dise0();	// <-_______Diseño_______
		getch();
	}
	else{
		Dise1();
		printf("\n%c    Ingrese ID    %c");
		Dise0();
		printf("\n\n\t*: ");
		scanf("%d", &id);
		printf("\n\n");
		Dise1();
		printf("\n%c  Ingrese Nombre  %c");
		Dise0();
		printf("\n\n\t*: ");
		scanf(" %[^\n]", &nombre);
		d->id[++c->final]=id;
		d->nombre[++c->final]=nombre;
	}
}

//--------------------------Desencolar - Eliminacion-------------------------
void Pop_Reajuste(cola *c, datos *d){
	int temp, i;
	char temp2[50];

	clrscr();

	if(c->final==-1){
		Design1();	// <-_______Diseño_______
		printf("\n%c        Subdesborde en la Cola         %c", 186, 186);
		Design0();	// <-_______Diseño_______
	}
	else{
		temp1=d->id[0];
		temp2=d->nombre[0];

		for(i=0;i<c->final;i++)
			d->nombre[i]=d->nombre[i+1];
			d->id[i]=d->id[i+1];
		c->final--;

		Design1();	// <-_______Diseño_______
		printf("\n%c          Elemento Eliminado           %c", 186, 186);
		Design0();	// <-_______Diseño_______
		printf("\n\n\t*: %d", temp1);
		printf("\n\n\t*: %s", temp2);
	}

	getch();
}

//--------------------Muestra el Frente y Final de la Cola-------------------
void Colafrentefinal(cola c, datos d){
	clrscr();

	if(c.final==-1){
		Dise1();	// <-_______Diseño_______
		printf("\n%c    Cola Vacia    %c", 186, 186);
		Dise0();	// <-_______Diseño_______
	}
	else{
		Design1();	// <-_______Diseño_______
		printf("\n%c       Elemento Frente de la Cola      %c", 186, 186);
		Design0();	// <-_______Diseño_______
		printf("\n\n\t*: %d", d.id[c.frente]);
		printf("\n\t*: %s", d.nombre[c.frente]);
		printf("\n\n");
		Design1();	// <-_______Diseño_______
		printf("\n%c       Elemento Final de la Cola       %c", 186, 186);
		Design0();	// <-_______Diseño_______
		printf("\n\n\t*: %d", d.id[c.final]);
		printf("\n\t*: %s", d.nombre[c.final]);
	}

	getch();
}

//---------------------Muestra el estado actual de la Cola-----------------
void Colastatus(cola c, datos d){
	int i;
	clrscr();

	if(c.final==-1){
		Dise1();	// <-_______Diseño_______
		printf("\n%c    Cola Vacia    %c", 186, 186);
		Dise0();	// <-_______Diseño_______
	}
	else{
		for(i=c.final;i>=0;i--){
			printf("\n%c   [%d]   %c", 186, i, 186);
			printf("\t%c \t*: %d", 26, d.id[i]);
			printf("\t%c \t*: %s", 26, d.nombre[i]);
		}
	}

	getch();
}

//**********************************Diseños**********************************
//-------------------------------Inicio Diseño #1----------------------------
void Design1(){
	int d;
	
	printf("\n%c", 201);
	for(d=0;d<39;d++)
		printf("%c", 205);
	printf("%c", 187);
}

//---------------------------------Fin Diseño #1-----------------------------
void Design0(){
	int d;

	printf("\n%c", 200);
	for(d=0;d<39;d++)
		printf("%c", 205);
	printf("%c", 188);
}

//---------------------------------Inicio Diseño #2---------------------------
void Dise1(){
	int d;

	printf("\n%c", 201);
	for(d=0;d<17;d++)
		printf("%c", 205);
	printf("%c", 187);
}

//-------------------------------Fin Diseño #3--------------------------------
void Dise0(){
	int d;

	printf("\n%c", 200);
	for(d=0;d<17;d++)
		printf("%c", 205);
	printf("%c", 188);
}


//-----------------------------Inicio Diseño #4-------------------------------
void Diseno1(){
	int d;

	printf("\n%c", 201);
	for(d=0;d<9;d++)
		printf("%c", 205);
	printf("%c", 187);
}

//----------------------------Fin Diseño #4------------------------------------
void Diseno0(){
	int d;

	printf("\n%c", 200);
	for(d=0;d<9;d++)
		printf("%c", 205);
	printf("%c", 188);
}




















		
		
		
		
		
		
		
		
		
