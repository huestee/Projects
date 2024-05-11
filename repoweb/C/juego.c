/*	Samuel Palma
	Prof. Lesbia Lacayo
	Ingeneria en Sistemas

	Ã¸Ã¸Ã¸-----------Proyecto:				Juego de la Vida----------Ã¸Ã¸Ã¸
	*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/*	Definimos los numeros de filas y columnas, por si en un futuro queremos
modicarla, solo le cambiamos el valor.
Numero de filas		*/
#define F 20
//Numero de columnas
#define C 20

//..............................Estructuras..................................
typedef struct{
	int vivos;
}Vecinos;

typedef struct{
 char var;
 float var2;
}Celdilla;

//..............Prototipos..de..Procedimientos..O..Funciones.................
void Menu();
char Validar1(char);
void Evaluamenu(Celdilla [F][C], char);
void Mostrar(Celdilla [F][C], int);
int Vecinosvivos(Celdilla [F][C]);
void Actualizar(Celdilla [F][C], char [F][C]);

/*..............Prototipos..de..Procedimientos..O..Funciones.................
..................................De.........................................
..........................."Opcion..Personalizar"..........................*/
void Menuperso();
void Tablaperso(Celdilla [F][C]);
void Actualizaentra(Celdilla [F][C], int, int);
void Mostrarperso(Celdilla [F][C], int);
int Vecinosperso(Celdilla [F][C]);
void Actualizaperso(Celdilla [F][C], float [F][C]);

main(){
	Vecinos veci;
	Celdilla celdi[F][C];

	int i, j;
	int num, num2;
	char opc;

	clrscr();

	do{
		system("cls");

		Menu();  //Muestra menu de opciones

		printf("\n\tSeleccione la opcion en que desea ejecutar el juego: ");
		fflush(stdin);
		scanf("%c", &opc);

		opc=Validar1(opc);		//Llamamos al Procedimiento

		if(opc>='a' && opc<'e'|| opc=='f'){
			printf("\nDigite el numero de veces que desea realizar el juego: ");
			scanf("%d", &num);

			Evaluamenu(celdi, opc);     	 //Llamamos al procedimiento
				//Muestra los datos de entrada del juego

			Mostrar(celdi, num);   //Llamamos al procedimiento
				//Muestra el resultado del juego
		}
		else if(opc=='e'){
			Menuperso();

			system("pause");	//Genera una pausa, para poder visualizar bien lo que
											//nos muestra.
			system("cls");		//Limpia pantalla

			Tablaperso(celdi);//Pide la posicion para las celdas vivas.

			printf("\nDigite el numero de veces que desea realizar el juego: ");
			scanf("%d", &num);

			Mostrarperso(celdi, num); //Llamamos al procedimiento
							//Muestra el resultado del juego/\.^.
		}
		else
			printf("\nERROR en el Sistema \"mensaje no deberia ser mostrado\"\n");

	}
	while(opc!='f');

	printf("\n\t\tHasta Luego \2");

	getch();
	return 0;
}


//-------------------------Funciones--O--Procedimientos---------------------
void Menu(){
	int i, j;

	//Menu de opciones para escoger como iniciara el juego
		printf("\n\n\n\n\n\n\t\t");
		for(i=0;i<1; i++){
			for(j=0;j<36; j++){
				if(j==0)
					printf("%s", "É");
				else if(j==35)
					printf("%s", "»");
				else
					printf("%s", "Í");

			}
		printf("\n");
		}

		printf("\t\t%s \tMenu De Opciones \t %3s", "º", "º");
		printf("\n\t\t%s\t\t%20s", "º", "º");
		printf("\n\t\t%s a. * *\tb. * * *\t %3s", "º", "º");
		printf("\n\t\t%s\t\t%20s", "º", "º");
		printf("\n\t\t%s c. * *\td. *\te.Personalizar%s", "º", "º");
		printf("\n\t\t%s    * *\t\t\t %3s", "º", "º");
		printf("\n\t\t%s\t\t%20s", "º", "º");
		printf("\n\t\t%sf.Salir\t\t%13s", "º", "º");

		printf("\n\t\t");

		for(i=0;i<1; i++){
			for(j=0;j<36; j++){
				if(j==0)
					printf("%s", "È");
				else if(j==35)
					printf("%s", "¼");
				else
					printf("%s", "Í");

			}
		printf("\n\n");
		}

}

//	Funciones(Procedimiento)
char Validar1(char o){
	//	Valida la seleccion de la opcion
	while(o<'a' || o>'f'){
		system("cls");

		Menu();
		printf("\n\t\tIntente nuevamente: ");
		fflush(stdin);
		scanf("%c", &o);
	}
	return o;
}


void Evaluamenu(Celdilla celdi1[F][C], char o){
	int i, j;

	//Este ciclo realiza el tamaÂ¤o de la tabla que tendra el juego
	//Y las celdillas de inicializan muertas
	for(i=0;i<F; i++){
		for(j=0;j<C; j++){
			celdi1[i][j].var='0';
		}
	}

	//Situa el estado en el que iniciara el juego, es decir las celdillas
//vivas que tendra el juego
	switch(o){
		case 'a':	celdi1[4][4].var='*';	celdi1[4][5].var='*';
			break;
		case 'b':	celdi1[4][4].var='*';	celdi1[4][5].var='*';
			celdi1[4][6].var='*';
			break;
		case 'c':	celdi1[4][4].var='*'; celdi1[4][5].var='*';
			celdi1[5][4].var='*';	celdi1[5][5].var='*';
			break;
		case 'd':	celdi1[4][4].var='*';
			break;
		case 'e': printf("\n\tERROR en el Sistemas\n");
			break;
		case 'f': printf("\tHasta Luego\n");
			break;
		default: printf("\n\tERROR en el Sistema  Area: Seleccion de opcion.\n");
		//	Entrada(celdi1);
		//Este mensaje se mostrara en caso que se produzca un
			break;																//en la validacion de la opcion.
	}
}


//----------------------------------------------------------------
void Mostrar(Celdilla celdi2[F][C], int n){
	char mundo1[F][C];
	int vivos;
	int e=0;
	int i, j;

//Este bucle evaluara las veces que se mostrara el juego de la vida
	while(e<=n){

		system("cls");

//Muestra la tabla del juego con la opcion elegida en el menu(sin modificar)
		for(i=0;i<F; i++){
			printf("\t");
			for(j=0;j<C; j++){
				if(celdi2[i][j].var=='*'){
					textcolor(BLUE);
					cprintf("%s", "Û");
				}
				else if(celdi2[i][j].var=='0'){
					textcolor(RED);
					cprintf("%s", "Û");
				}
			}
			printf("\n");
		}

		system("pause"); //Generamos pausa, para visualizar cada estado de la
			 //tabla es decir, haci como el original y cada modificacion que tendra.

	/*Este ciclo recorre cada posicion de la tabla, de la misma forma evalua
	los ocho vecinos  de la celda  */
		for(i=0;i<F; i++){
			for(j=0;j<C; j++){

				vivos=Vecinosvivos(celdi2); //Llamamos a la funcion

			//Este condicional evalua si la celda estara viva o muerta en el futuro.
				if(celdi2[i][j].var=='*'){

					//Si la celda esta viva se evalua la sig. condicion
					if(vivos>=2 && vivos<=3){
						mundo1[i][j]='*';
					}
					else if(vivos>=4 || vivos==1){
						mundo1[i][j]='0';
						}
					else
					/*Este mensaje se mostrara solo en caso que haiga error al momento
					de evaluar las celdas vivas	*/
						printf("\nERROR en el Sistema\nArea: Celdas Vivas\n");
				}
				else{

					//Si la celda esta muerta se evalua la sig.condicion.
					if(vivos==3){
						mundo1[i][j]='*';
					}
					else
						mundo1[i][j]='0';
				}

			}	//for
		} //for

		Actualizar(celdi2, mundo1);	//Llamamos al procedimiento

		e+=1;

	}	//while
}


int Vecinosvivos(Celdilla celda[F][C]){
	Vecinos veci;
	int i, j;

	veci.vivos=0;

	//Estas condiciones nos permitiran evaluar las ocho celdas vecinas.
	//Evalua si los ocho vecinos de una celda estan vivos.
	if(celda[i-1][j-1].var=='*'){
		veci.vivos+=1;
	}

		if(celda[i-1][j].var=='*'){
			veci.vivos+=1;
		}

			if(celda[i-1][j+1].var=='*'){
				veci.vivos+=1;
			}

			if(celda[i][j-1].var=='*'){
				veci.vivos+=1;
			}

				if(celda[i][j+1].var=='*'){
					veci.vivos+=1;
				}

					if(celda[i+1][j-1].var=='*'){
						veci.vivos+=1;
					}

						if(celda[i+1][j].var=='*'){
							veci.vivos+=1;
						}

							if(celda[i+1][j+1].var=='*'){
								veci.vivos+=1;
							}

	/*Incrementa los valores de "i" y "j", funciona al igual que un bucle a
	excepcion que su valor incrementa cada vez que entramos al procedimiento */
	j+=1;

	if(j==C){
		i+=1;
		j=0;
	}

	return veci.vivos;
}

void Actualizar(Celdilla celdi3[F][C], char mundo[F][C]){
	int i, j;
	/*Guardamos la estructura de la tabla celdi2[i][j].var2 en la
	estructura de la tabla celdi2[i][j].var	 -|- Para que la proxima vez
	que entre en el bucle la muestre actualizada	 */
	for(i=0;i<F; i++){
		for(j=0;j<C; j++){
			celdi3[i][j].var=mundo[i][j];
		}
	}
}

/*^^^^^_____._____^^^^^^_____.______^^^^^^______.______^^^^^^_____._____^^^^^

-------------Procedimientos--O--Funciones--"Opcion--Personalizar"------------
/\\.//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\*/
void Menuperso(){
	int i, j;

	//Menu de opciones para escoger como iniciara el juego
		printf("\n\t\t");
		for(i=0;i<1; i++){
			for(j=0;j<36; j++){
				if(j==0)
					printf("%s", "É");
				else if(j==35)
					printf("%s", "»");
				else
					printf("%s", "Í");

			}
		printf("\n");
		}

		printf("\t\t%s\tIngrese los datos\t %3s", "º", "º");
		printf("\n\t\t%s \t20s", "º", "º");
		printf("\n\t\t%s  Ingrese la posicion en %3s", "º", "º");
		printf("\n\t\t%sen que desea situar una\t%20s", "º", "º");
		printf("\n\t\t%sceldilla viva", "º", "º");
		printf("\n\t\t%s\t\t%20s", "º", "º");
		printf("\n\t\t%s\tf.Salir \t%3s", "º", "º");

		printf("\n\t\t");

		for(i=0;i<1; i++){
			for(j=0;j<36; j++){
				if(j==0)
					printf("%s", "È");
				else if(j==35)
					printf("%s", "¼");
				else
					printf("%s", "Í");

			}
		printf("\n\n");
		}
}


void Tablaperso(Celdilla cperso[F][C]){
	float posi=0.0;
	float conver1;
	int conver2, conver3;
	int color=0;
	int i, j;
	char o[4];

	//Bucle almacena numero de posiciones que tiene el juego
	for(i=0;i<F; i++){
		for(j=0;j<C; j++){
			fflush(stdin);
			cperso[i][j].var2=posi;
			posi+=0.1;
		}
	}

	do{
		system("cls");		//Limpia panatalla

		//Ciclo muestra el numero de posiciones del juego
		for(i=0;i<F; i++){
			for(j=0;j<C; j++){
				fflush(stdin);
				if(i==color){
					textcolor(BLUE);
					if(j==C-1)
						color+=2;
				}
				else
					textcolor(RED);

				if(i<10)
					cprintf(" ");

				cprintf("%.1f", cperso[i][j].var2);
			}
			printf("\n");
		}

		printf("\t%c%c: ","Í","");
		fflush(stdin);
		scanf(" %[^\n]", &o);

		//Convierte el numero de la cadena en un flotante
		conver1=atof(o);
		//Convierte el fotante en un entero
		conver2=((int)conver1);
		//convierte los decimales del floante en un entero
		conver3=((int)((conver1-conver2)*10));

		Actualizaentra(cperso, conver2, conver3);
	}
	while(o!="f" && o!="F");

}

void Actualizaentra(Celdilla cperso2[F][C], int c1, int c2){
	int i, j;
	float p=0.0;

	//Guarda una celda viva en la posicion ungresada por el usuario
	for(i=0;i<F; i++){
		for(j=0;j<C; j++){
			p+=0.1;
			if(i==c1 && j==c2)
				cperso2[i][j].var2=-1;
			else
				cperso2[i][j].var2=p;
		}
	}
}

//_________________________________________________________________________
void Mostrarperso(Celdilla cperso3[F][C], int n1){
	float mundoperso[F][C];
	int vivos;
	int e=0;
	int i, j;

	//Este bucle evaluara las veces que se mostrara el juego de la vida
	while(e<=n1){

		system("cls");

//Muestra la tabla del juego con la opcion elegida en el menu(sin modificar)
		for(i=0;i<F; i++){
			printf("\t");
			for(j=0;j<C; j++){
				if(cperso3[i][j].var2==-1){
					textcolor(BLUE);
					cprintf("%s", "Û");
				}
				else if(cperso3[i][j].var2!=-1){
					textcolor(RED);
					cprintf("%s", "Û");
				}
			}//for
			printf("\n");
		}//for

		system("pause"); //Generamos pausa, para visualizar cada estado de la
			 //tabla es decir, haci como el original y cada modificacion que tendra.

	/*Este ciclo recorre cada posicion de la tabla, de la misma forma evalua
	los ocho vecinos  de la celda  */
		for(i=0;i<F; i++){
			for(j=0;j<C; j++){

				vivos=Vecinosperso(cperso3); //Llamamos a la funcion

			//Este condicional evalua si la celda estara viva o muerta en el futuro.
				if(cperso3[i][j].var2==-1){

					//Si la celda esta viva se evalua la sig. condicion
					if(vivos>=2 && vivos<=3){
						mundoperso[i][j]=-1;
					}
					else if(vivos>=4 || vivos==1){
						mundoperso[i][j]=0;
						}
					else
					/*Este mensaje se mostrara solo en caso que haiga error al momento
					de evaluar las celdas vivas	*/
						printf("\nERROR en el Sistema\nArea: Celdas Muertas\n");
				}
				else{

					//Si la celda esta muerta se evalua la sig.condicion.
					if(vivos==3){
						mundoperso[i][j]=-1;
					}
					else
						mundoperso[i][j]=0;
				}

			}	//for
		} //for

		Actualizaperso(cperso3, mundoperso);	//Llamamos al procedimiento

		e+=1;

	}	//while
}


int Vecinosperso(Celdilla celda[F][C]){
	Vecinos veci;
	int i, j;

	veci.vivos=0;

	//Estas condiciones nos permitiran evaluar las ocho celdas vecinas.
	//Evalua si los ocho vecinos de una celda estan vivos.
	if(celda[i-1][j-1].var2==-1){
		veci.vivos+=1;
	}

		if(celda[i-1][j].var2==-1){
			veci.vivos+=1;
		}

			if(celda[i-1][j+1].var2==-1){
				veci.vivos+=1;
			}

			if(celda[i][j-1].var2==-1){
				veci.vivos+=1;
			}

				if(celda[i][j+1].var2==-1){
					veci.vivos+=1;
				}

					if(celda[i+1][j-1].var2==-1){
						veci.vivos+=1;
					}

						if(celda[i+1][j].var2==-1){
							veci.vivos+=1;
						}

							if(celda[i+1][j+1].var2==-1){
								veci.vivos+=1;
							}

	/*Incrementa los valores de "i" y "j", funciona al igual que un bucle a
	excepcion que su valor incrementa cada vez que entramos al procedimiento */
	j+=1;

	if(j==C){
		i+=1;
		j=0;
	}

	return veci.vivos;
}


void Actualizaperso(Celdilla cperso4[F][C], float mundoperso2[F][C]){
	int i, j;
	/*Guardamos la estructura de la tabla celdi2[i][j].var2 en la
	estructura de la tabla celdi2[i][j].var	 -|- Para que la proxima vez
	que entre en el bucle la muestre actualizada	 */
	for(i=0;i<F; i++){
		for(j=0;j<C; j++){
			cperso4[i][j].var2=mundoperso2[i][j];
		}
	}
}