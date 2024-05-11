/****************************************************************************
Name				: PILA.C
Author			:	Samuel Palma
Career			:	Ingenieria en Sistemas
Copyright		: Todos los derechos reservados © 2019.
Description	: Pila en C, insertar, eliminar, y mostrar datos.
****************************************************************************/

#include<stdio.h>
#include<conio.h>

#define STACKSIZE 10

typedef struct{
		int items[STACKSIZE];
		int tope;
}stack;

main(){
	stack pila;
	char opcion;
	int cant, i, id, temp;
	int d; //***Dise¤o
	pila.tope=-1;

	clrscr();

	do{
		clrscr();

		//______________________Diseño_____________________//
		printf("%c", 201);                                 //
		for(d=0;d<36;d++)                                  //
			printf("%c", 205);                             //
		printf("%c", 187);                                 //
		//_____________________Fin Diseño__________________//

		printf("\n%c               Menu                 %c", 186, 186);
		printf("\n%c     1. Insertar Elemento           %c", 186, 186);//Pusp
		printf("\n%c     2. Sacar Elemento              %c", 186, 186);//Pop
		printf("\n%c     3. Mostrar Elemento Cima       %c", 186, 186);//Stacktope
		printf("\n%c     4. Mostrar Estado de la Pila   %c", 186, 186);//Stackstatus
		printf("\n%c     s: Salir                       %c", 186, 186);//Salir

		//______________________Diseño_____________________//
		printf("\n%c", 200);                                 //
		for(d=0;d<36;d++)                                  //
			printf("%c", 205);                             //
		printf("%c", 188);                                 //
		//_____________________Fin Diseño__________________//

		printf("\n\n\t Opcion: ");
		fflush(stdin);
		scanf(" %c", &opcion);

		switch(opcion){
			//_____________________Operacion Push_____________________
			case '1':
				clrscr();

				//______________________Diseño_____________________//
				printf("\n%c", 201);                                 //
				for(d=0;d<35;d++)                                  //
					printf("%c", 205);                             //
				printf("%c", 187);                                 //
				//_____________________Fin Diseño__________________//

				printf("\n%c       Cantidad de Elementos       %c", 186, 186);

				//______________________Diseño_____________________//
				printf("\n%c", 200);                                 //
				for(d=0;d<35;d++)                                  //
					printf("%c", 205);                             //
				printf("%c", 188);                                 //
				//_____________________Fin Diseño__________________//

				printf("\n\n\t *:");
				scanf("%d", &cant);

				clrscr();

				if(cant>STACKSIZE){
					printf("\n\n\t*Sobrecarga");
					getch();
				}
				else{
					for(i=0;i<cant;i++){
						clrscr();

						if(pila.tope==STACKSIZE-1){
							printf("\n\n\t*Desbordamiento");
							getch();
							break;
						}
						else{
							//______________________Diseño_____________________//
							printf("\n%c", 201);                                 //
							for(d=0;d<35;d++)                                  //
								printf("%c", 205);                             //
							printf("%c", 187);                                 //
							//_____________________Fin Diseño__________________//

							printf("\n%c                 ID                %c", 186, 186);

							//______________________Diseño_____________________//
							printf("\n%c", 200);                                 //
							for(d=0;d<35;d++)                                  //
								printf("%c", 205);                             //
							printf("%c", 188);                                 //
							//_____________________Fin Diseño__________________//

							printf("\n\n\t *: ");
							scanf("%d", &id);

							pila.tope+=1;
							pila.items[pila.tope]=id;
						}
					}
				}
				fflush(stdin);
				break;
			//_____________________Operacion Pop__________________________
			case '2':
				clrscr();

				if(pila.tope==-1)
					printf("\n\n\t*Subdesborde en la Pila");
				else{
					temp=pila.items[pila.tope];
					pila.tope=pila.tope-1;

					//______________________Diseño_____________________//
					printf("\n%c", 201);                                 //
					for(d=0;d<34;d++)                                  //
						printf("%c", 205);                             //
					printf("%c", 187);                                 //
					//_____________________Fin Diseño__________________//

					printf("\n%c     Elemento Eliminado    %c%c     %c", 186, 205, 16, 186);

					//______________________Diseño_____________________//
					printf("\n%c", 200);                                 //
					for(d=0;d<34;d++)                                  //
						printf("%c", 205);                             //
					printf("%c", 188);                                 //
					//_____________________Fin Diseño__________________//

					printf("\t%d", temp);
				}

				fflush(stdin);
				getch();
				break;
			//_____________________Operacion Stacktope_____________________
			case '3':
				clrscr();

				if(pila.tope==-1)
					printf("\n\n\t*Pila Vacia");
				else{
					//______________________Diseño_____________________//
					printf("\n%c", 201);                                 //
					for(d=0;d<34;d++)                                  //
						printf("%c", 205);                             //
					printf("%c", 187);                                 //
					//_____________________Fin Diseño__________________//

					printf("\n%c    Elemento en la Cima    %c%c     %c", 186, 205, 16, 186);

					//______________________Diseño_____________________//
					printf("\n%c", 200);                                 //
					for(d=0;d<34;d++)                                  //
						printf("%c", 205);                             //
					printf("%c", 188);                                 //
					//_____________________Fin Diseño__________________//

					printf("\t%d", pila.items[pila.tope]);
				}
				fflush(stdin);
				getch();
				break;
			//_____________________Operacion Stackstatus___________________
			case '4':
				clrscr();
				if(pila.tope==-1)
					printf("\n\n\t*Pila Vacia");
				else{

					for(i=pila.tope;i>=0;i--){
						
						//______________________Diseño_____________________//
						printf("\n%c", 201);                                 //
						for(d=0;d<23;d++)                                  //
							printf("%c", 205);                             //
						printf("%c", 187);                                 //
						//_____________________Fin Diseño__________________//

						printf("\n%c      [%d]      %c%c      %c", 186, i, 205, 16, 186);

						//______________________Diseño_____________________//
						printf("\n%c", 200);                                 //
						for(d=0;d<23;d++)                                  //
							printf("%c", 205);                             //
						printf("%c", 188);                                 //
						//_____________________Fin Diseño__________________//

						printf("\t%d", pila.items[i]);
					}
				}

				fflush(stdin);
				getch();
				break;
			//_____________________Operacion Salir_________________________
			case 's':
			case 'S':
				clrscr();

				printf("\n\n\t *Hasta Luego. ");
				fflush(stdin);
				getch();
				break;
			//_____________________Digito Incorrecto_______________________
			default:
				clrscr();

				printf("\n\n\t*Error, digito no valido.");
				fflush(stdin);
				getch();
				break;
		}
	}
	while(opcion!='s' && opcion!='S');

	return 0;
}
