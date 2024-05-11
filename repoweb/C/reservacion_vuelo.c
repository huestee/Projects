/*	Samuel Palma
	Prof. Lesbia Lacayo

	Proyecto "Reservacion de un vuelo"	*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

		//Prototipos
int N_asientos(int N);
int M_asientos(int M, int N);
int areafumar1(int N);
int areafumar2(int M);
void mostrar1(int N, int clase1[50][4]);
void mostrar2(int M, int clase2[50][6]);

main(){

	int i, j, N, M, status=0, cont1=0, cont2=0, contar1=0, contar2=0;
	//Asientos: 1ra clase N y 2da classe M
	int fila, col;
	int clase, sec;
	char posi[1];
	char ruta[1];
	int clase1[50][4]={0};
	int clase2[50][6]={0};

	clrscr();

	printf("\t Sistema de Reservacion de un Vuelo\n");

	//Llamamos a las funciones y asignamos su valor a otra variable
	N=N_asientos(N);
	M=M_asientos(M, N);

	//Llamamos al procedimiento para que muestre los asientos disponibles.
	mostrar1(N, clase1);
	mostrar2(M, clase2);

	//Prioridades para reservar un asiento
	printf("\t\4 Escoja un Asiento\n");

	do{		//Ciclo solo acepta numero  asociados 1 o 2.
		printf("\2 Clase (1 o 2): ");//1ra clase , 2da clase
		scanf("%d", &clase);
	}
	while(clase!=1 || clase!=2);

	do{		//Ciclo solo acepta numero asociados 1 o 2.
		printf("\2 Seccion\n1.No Fumador\n2. Fumador"); //Fumador o no fumador
		scanf("%d", &sec);
	}
	while(sec!=1 || sec!=2);

	do{		//Ciclo solo acepta caracter asociado V o C o P.
		printf("\2 Posicion\nV: Ventanilla\nC: Central\nP: Pasillo");
		scanf("%c", &posi[0]);
	}
	while(posi[0]!='V' || posi[0]!='C' || posi[0]!='P');

	printf("\n");

	switch(clase){
		case 1: //Evalua las prioridades para un asiento.
				//Ciclo evalua posicion de asiento.
				printf("\2 Escoja un lugar de asiento\n");
			do{
				printf("Digite la columna del asiento: ");
				scanf("%d", &col);
			}
			while(col!=1 || col!=4);

			if(sec==1 && posi[0]=='V'){ //Ventanilla         //No Fumador
				if(contar1<=areafumar1(N)){
					while(status==0){

						//Este ciclo muestra tos los asientos disponibles y reservados.
						for(i=0;i<N; i++){
							for(j=0;j<4; j++){
								if(clase1[i][0]==0 || clase1[i][3]==0){
									clase1[i][col-1]=1;
									printf("|%d|", clase1[i][j]);
									contar1++;
									status=1;
									cont1+=1;
									if(j==1){
										printf(" ");
									}
										if(cont1==N){
											j=4;
											i=N-1;
										}
								} //if
							}//for
							printf("\n");
						}//for

					}//while
				}
				system("pause");
				printf("\n");
			}//if

			break;

			else{
				do{
				printf("La posicion de Ventanilla esta llena.\n");
				printf("Le gustaria que le asignemos un lugar en el pasillo (s/n)");
				scanf("%s", &ruta[0]);
				}
				while(ruta!='s' || ruta!='n');

				if(ruta[0]=='s'|| ruta[0]=='S'){
					if(sec==1 && posi[0]=='P'){ //Ventanilla         //No Fumador
						if(contar1<=areafumar1(N)){

							while(status==0){
								for(i=0;i<N; i++){
									for(j=0;j<4; j++){
										if(clase1[i][1]==0 || clase1[i][2]==0){
											clase1[i][j]=1;
											printf("|%d|", clase1[i][j]);
											contar1++;
											status=1;
											cont1+=1;
											if(j==1){
												printf(" ");
											}
												if(cont1==N){
													j=4;
													i=N-1;
												}
										}//if
									}//for
								}//for
								printf("\n");
							}//while

						}//if
					}//if
					system("pause");
					printf("\n");
				}//if

				break;

				else{
					printf("La seccion de No Fumadores esta llena.\n");
					do{
						printf("Le gustaria que le asignemos un lugar en la seccion");
						printf(" de Fumadores(s/n)");
						scanf("%s", &ruta[0]);
					while(ruta[0]!='s' || ruta[0]!='n');

					if(ruta[0]=='s'|| ruta[0]=='S'){

						do{		//Ciclo evalua posicion de asiento.
							printf("\2 Escoja un lugar de asiento\n");
							printf("Digite la columna del asiento: ");
							scanf("%d", &col);
						while(col!=1 || col!=4);

						if(sec==2 && posi[0]=='V'){ //Ventanilla         //Fumador
							if(contar1<=N-areafumar1(N)){
								while(status==0){

								//Este ciclo muestra tos los asientos disponibles y reservados.
									for(i=0;i<N; i++){
										for(j=0;j<4; j++){
											if(clase1[i][0]==0 || clase1[i][3]==0){
												clase1[i][col-1]=1;
												printf("|%d|", clase1[i][j]);
												contar2++;
												status=1;
												cont2+=1;
												if(j==1){
													printf(" ");
												}
												if(cont2==N){
													j=4;
													i=N-1;
												}
											} //if
										}//for
										printf("\n");
									}//for
								}//while
							}//if
							system("pause");
							printf("\n");
						}//if

						break;

						else{
							printf("La posicion de Ventanilla esta llena.\n");
							do{
							printf("Le gustaria que le asignemos un lugar en el pasillo (s/n)");
							scanf("%s", &ruta[0]);
							}
							while(ruta[0]!='s' || ruta[0]!='n');
							if(ruta[0]=='s'|| ruta[0]=='S'){
							if(sec==1 && posi[0]=='P'){ //Ventanilla         //Fumador
							if(contar2<=N-areafumar1(N)){

							while(status==0){
								for(i=0;i<N; i++){
									for(j=0;j<4; j++){
										if(clase1[i][1]==0 || clase1[i][2]==0){
											clase1[i][j]=1;
											printf("|%d|", clase1[i][j]);
											contar2++;
											status=1;
											cont2+=1;
											if(j==1){
												printf(" ");
											}
												if(cont2==N){
													j=4;
													i=N-1;
												}
										}//if
									}//for
								}//for
								printf("\n");
							}//while
							}//if
							}//if
							system("pause");
							printf("\n");
							}//if

							break;

							else{
								printf("Ya no hay asientos dispobles en 1ra Clase\n");
								do{
								printf("Desea cambiarse de clase (s/n): ");
								scanf("%c", &ruta[0]);
								}
								while(ruta[0]!='s' || ruta[0]!='n');

								if(ruta[0]=='s'|| ruta[0]=='S'){
									sec=2;

								break;

								else{
									printf("Tendra que esperar el siguiente vuelo\n");
								}
							}//else
						}//else
				}//else
			}//else

		case 2: //Evalua las prioridades para un asiento.
				//Ciclo evalua posicion de asiento.
				printf("\2 Escoja un lugar de asiento\n");
			do{
				printf("Digite la columna del asiento: ");
				scanf("%d", &col);
			}
			while(col!=1 || col!=6);

			if(sec==2 && posi[0]=='V'){ //Ventanilla         //No Fumador
				if(contar1<=areafumar2(M)){
					while(status==0){

						//Este ciclo muestra tos los asientos disponibles y reservados.
						for(i=0;i<M; i++){
							for(j=0;j<6; j++){
								if(clase2[i][0]==0 || clase2[i][5]==0){
									clase2[i][col-1]=1;
									printf("|%d|", clase2[i][j]);
									contar1++;
									status=1;
									cont1+=1;
									if(j==2){
										printf(" ");
									}
										if(cont1==M){
											j=6;
											i=M-1;
										}
								} //if
							}//for
							printf("\n");
						}//for

					}//while
				}
				system("pause");
				printf("\n");
			}//if

			break;

			else{
				do{
				printf("La posicion de Ventanilla esta llena.\n");
				printf("Le gustaria que le asignemos un lugar en el centro (s/n)");
				scanf("%s", &ruta[0]);
				}
				while(ruta!='s' || ruta!='n');
				if(sec==2 && posi[0]=='C'){ //Ventanilla         //No Fumador
				if(contar1<=areafumar2(M)){
					while(status==0){

						//Este ciclo muestra tos los asientos disponibles y reservados.
						for(i=0;i<M; i++){
							for(j=0;j<6; j++){
								if(clase2[i][1]==0 || clase2[i][4]==0){
									clase2[i][j]=1;
									printf("|%d|", clase2[i][j]);
									contar1++;
									status=1;
									cont1+=1;
									if(j==2){
										printf(" ");
									}
										if(cont1==M){
											j=6;
											i=M-1;
										}
								} //if
							}//for
							printf("\n");
						}//for

					}//while
				}
				system("pause");
				printf("\n");
				}//if

				else{
				do{
				printf("La posicion de centro esta llena.\n");
				printf("Le gustaria que le asignemos un lugar en el pasillo (s/n)");
				scanf("%s", &ruta[0]);
				}
				while(ruta!='s' || ruta!='n');
				if(sec==2 && posi[0]=='P'){ //pasillo         //No Fumador
				if(contar1<=areafumar2(M)){
					while(status==0){

						//Este ciclo muestra tos los asientos disponibles y reservados.
						for(i=0;i<M; i++){
							for(j=0;j<6; j++){
								if(clase2[i][2]==0 || clase2[i][3]==0){
									clase2[i][j]=1;
									printf("|%d|", clase2[i][j]);
									contar1++;
									status=1;
									cont1+=1;
									if(j==2){
										printf(" ");
									}
										if(cont1==M){
											j=6;
											i=M-1;
										}
								} //if
							}//for
							printf("\n");
						}//for

					}//while
				}
				system("pause");
				printf("\n");
				}//if

				else{
					printf("La seccion de No Fumadores esta llena.\n");
					do{
						printf("Le gustaria que le asignemos un lugar en la seccion");
						printf(" de Fumadores(s/n)");
						scanf("%s", &ruta[0]);
					}
					while(ruta[0]!='s' || ruta[0]!='n');

					if(ruta[0]=='s'|| ruta[0]=='S'){

						do{		//Ciclo evalua posicion de asiento.
							printf("\2 Escoja un lugar de asiento\n");
							printf("Digite la columna del asiento: ");
							scanf("%d", &col);
						while(col!=1 || col!=6);

						if(sec==2 && posi[0]=='V'){ //Ventanilla         No Fumador
							if(contar2<=M-areafumar2(M)){
								while(status==0){

								//Este ciclo muestra tos los asientos disponibles y reservados.
									for(i=0;i<M; i++){
										for(j=0;j<6; j++){
											if(clase2[i][0]==0 || clase2[i][5]==0){
												clase2[i][col-1]=1;
												printf("|%d|", clase2[i][j]);
												contar2++;
												status=1;
												cont2+=1;
												if(j==2){
													printf(" ");
												}
												if(cont2==M){
													j=6;
													i=M-1;
												}
											} //if
										}//for
										printf("\n");
									}//for
								}//while
							}//if
							system("pause");
							printf("\n");
						}//if

						break;

						else{
							printf("La posicion de ventanilla esta llena.\n");
							do{
							printf("Le gustaria que le asignemos un lugar en el pasillo (s/n)");
							scanf("%s", &ruta[0]);
							}
							while(ruta[0]!='s' || ruta[0]!='n');
							if(ruta[0]=='s'|| ruta[0]=='S'){
							if(sec==2 && posi[0]=='C'){ //Ventanilla         No Fumador
							if(contar2<=M-areafumar2(M)){

							while(status==0){
								for(i=0;i<M; i++){
									for(j=0;j<6; j++){
										if(clase2[i][1]==0 || clase2[i][4]==0){
											clase2[i][j]=1;
											printf("|%d|", clase2[i][j]);
											contar2++;
											status=1;
											cont2+=1;
											if(j==2){
												printf(" ");
											}
												if(cont2==M){
													j=6;
													i=M-1;
												}
										}//if
									}//for
								}//for
								printf("\n");
							}//while
							}//if
							}//if
							system("pause");
							printf("\n");
							}//if

							break;

							else{

							printf("La posicion de centro esta llena.\n");
							do{
							printf("Le gustaria que le asignemos un lugar en el pasillo (s/n)");
							scanf("%s", &ruta[0]);
							}
							while(ruta[0]!='s' || ruta[0]!='n');
							if(ruta[0]=='s'|| ruta[0]=='S'){
							if(sec==2 && posi[0]=='P'){ //Ventanilla          Fumador
							if(contar2<=M-areafumar2(M)){

							while(status==0){
								for(i=0;i<M; i++){
									for(j=0;j<6; j++){
										if(clase2[i][1]==0 || clase2[i][4]==0){
											clase2[i][j]=1;
											printf("|%d|", clase2[i][j]);
											contar2++;
											status=1;
											cont2+=1;
											if(j==2){
												printf(" ");
											}
												if(cont2==M){
													j=6;
													i=M-1;
												}
										}//if
									}//for
								}//for
								printf("\n");
							}//while
							}//if
							}//if
							system("pause");
							printf("\n");
							}//if

							break;

							else{
								printf("Ya no hay asientos dispobles en 1ra Clase\n");
								do{
								printf("Desea cambiarse de clase (s/n): ");
								scanf("%c", &ruta[0]);
								}
								while(ruta[0]!='s' || ruta[0]!='n');

								if(ruta[0]=='s'|| ruta[0]=='S'){
									sec=2;

								break;

								else{
									printf("Tendra que esperar el siguiente vuelo\n");
								}
							}//else
							}//else
						}//else
				}//else
				}//else
			}//else


	getch();
	return 0;
}

void mostrar1(int N, int clase1[50][4]){
	int i, j;

	for(i=0;i<N; i++){
		for(j=0;j<4; j++){
			printf("|%d|", clase1[i][j]);
			cont1+=1;
			if(j==1){
				printf(" ");
			}
				if(cont1==N){
					j=4;
					i=N-1;
				}
		}
		printf("\n");
	}

	system("pause");
	printf("\n");

}

void mostrar2(int M, int clase2[50][6]){
	int i, j;

	for(i=0;i<M; i++){
		for(j=0;j<6; j++){
			printf("|%d|", clase2[i][j]);
			cont2+=1;
			if(j==2){
				printf(" ");
			}
				if(cont2==M){
					j=6;
					i=M-1;
				}
		}
		printf("\n");
	}
}

int N_asientos(int N){	//Funcion para leer N asiento de 1ra clase.

	printf("Ingrese numero de asientos de primera clase: ");
	scanf("%d", &N);

	return N;
}


int M_asientos(int M, int N){	//Funcion para leer M asientos de 2da clase.

	printf("Ingrese el numero de asientos de segunda clase :");
	scanf("%d", &M);

	while(M<=N || N>=M){	//Validacion de M asientos
		printf("ERROR; Tiene que haber mas asientos de segunda clase\n");
		printf("Ingrese el numero de asientos de segunda clase :");
		scanf("%d", &M);
	}
	return M;
}

int areafumar1(int N){	//Funcion para una operacion
	int a;

	(int)a=(2*N)/3);	//2/3 de asientos de clase1 son para no fumadores.

	return a;
}

int areafumar2(int M){	//Funcion para una operacion
	int b;

 (int)b=(2*M)/3);	//2/3 de asientos de clase2 son para no fumadores.

	return b;
}