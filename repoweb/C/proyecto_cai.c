/*	CAI (Instruccion Asistida por Computadoras)

	�Este programa ayudara a un alumno a aprender a multiplicar con 2 numeros
enteros positivos de un digito.

	�Si el alumno responde correctamente se le enviara un mensaje correcto,
si no un inccorrecto, los mensajes varian en forma aleatoria.

	->Nota:
	Opcionalmente al programa se le agrego una repeticion de 10 preguntas de
multiplicar, despues de 10 preg. el programa pedira si quiere continuar o
desea salir.

	Teniendo en cuenta que no responder correctamente a la pregunta de
multiplicar, esta se repetira hasta ser contestada de la manera correcta.	*/

#include<stdio.h>
#include<stdlib.h>    //Libreria para el uso del rand
#include<conio.h>     //Esta libreria la utilizo para el getch
#include<time.h>  	 //Libreria para el uso de time

//Prototipos de funcion
int aleatorio1();
int aleatorio2();
int multiplicacion(int, int);

//Prototipos de procedimientos
void bienvenida();
void respuestas(int, int);
void preg(char [1]);

char nom1[80];

main(){
	int num1, num2;
	int rmulti, resultado;
	int i;
	char opc[1];

	clrscr();

	srand(getpid());

	bienvenida();		//Llamada al procedimiento, da bienvenida al alumno

	printf("\n");

	do{
		printf("\tTe deseo buena suerte.\n");

		for(i=0;i<10;i++){
			num1=aleatorio1();  //Llamamos a la funciones
			//system("Pause"); 		//generamos una pausa para que no se genere los
													//mismos numeros aletorios.
			num2=aleatorio2();  //			||

			printf("\n\tCuanto es: %d * %d: ", num1, num2);
			//fflush(stdin);    //limpia el buffer
			scanf("%d", &resultado);
			while(getchar()!='\n');   //sirve para leer todos los caracteres antes
																//de que enter sea presionado, tambien sirve
																	//como limpiador de buffer

			rmulti=multiplicacion(num1, num2);	//Llamamos a la funcion

			respuestas(rmulti, resultado); //Llammos al procedimiento
			printf("\n\n");

			while(resultado!=rmulti){
				printf("\n\tCuanto es: %d * %d: ", num1, num2);
				//fflush(stdin);           //limpia el buffer
				scanf("%d", &resultado);
				while(getchar()!='\n');

				rmulti=multiplicacion(num1, num2); 	//Llamamos a la funcion

				respuestas(rmulti, resultado);		//Llammos al procedimiento
				printf("\n");
			}
		}

		printf("\nDesea finalizar (S/N): ");
		fflush(stdin);         //Limpia el buffer
		scanf(" %c", &opc[0]);
		while(getchar()!='\n'); //Limpia el buffer

		preg(opc);

		printf("\n\n");
	}
	//evaluara si desea salir o no.
	while(opc[0]!='S' && opc[0]!='s');

	printf("\tHasta Luego %s \3", nom1);
	printf("\nFuen un gusto tenerte en nuestro programa educativo, cuidate \2");

	getch();
	return 0;
}

//Procedimiento da la bienvenida al alumno
void bienvenida(){

	printf("\nTe ense�aremos a multiplicar con numeros de un digito.");

	printf("\nAntes de empezar. Digite su nombre: ");
	fflush(stdin);   //Limpia el buffer
	scanf(" %[^\n]", &nom1);
	while(getchar()!='\n');

	printf("\n\tMucho gusto %s", nom1);
	printf("\nBueno no se diga mas empecemos con el aprendizaje\2");

	printf("\nOjo:\n");
	printf("Debes contestar de manera correcta y sin copiase, las sig. preguntas.\n");
	printf("Para que pongas a prueba tus conocimentos y te retroalimentes deigual manera\n");
}


//funcion saca numero aleatorios
int aleatorio1(){
	int a;

	srand(time(NULL));  //semilla de rand
	a=1+(rand()%10);     //Numero Aleatorio

	return a;
}

//Funcion saca otro numero aleatorio
int aleatorio2(){
	int b;

	srand(time(NULL));		//semilla de rand
	b=1+(rand()%10);				     //Numero aleatorio

	return b;
}

//funcion ejecuta multiplicacion
int multiplicacion(int x, int y){
	int resul;

//halla la multilicacion de los 2 numeros aleatorios dados por defecto
	if(y==1)
		resul=x;
	else
		resul=x+multiplicacion(x, y-1);

	return resul;
}

//Procedimiento
void respuestas(int r1, int r2){
	int n1;
	char nomb[80];

	srand(time(NULL));  //semilla de rand

//Evalua si la repuesta introducida por el alumno es correcta o no lo es.
	if(r2==r1){
		fflush(stdin);
		n1=1+(rand()%4);  //halla un numero aletorio para elegir una respuesta.

		switch(n1){
			case 1:
				printf("Muy Bien! %s", nom1);
				break;

			case 2:
				printf("Exelente! %s", nom1);
				break;

			case 3:
				printf("Buen Trabajo! %s", nom1);
				break;

			case 4:
				printf("Mantente arriba hiciste buen trabajo! %s", nom1);
				break;

			default:
				printf("\a\aERROR en el Sistema\nEste sms no se deberia de mostrar");
				break;
		}
	}
	else{
		n1=1+(rand()%4);  //halla un numero aletorio

		switch(n1){
			case 1:
				printf("%s No. Por favor prueba de nuevo.", nom1);
				break;

			case 2:
				printf("Error. %s Pueba una vez mas.", nom1);
				break;

			case 3:
				printf("No. %s Intentalo de nuevo.", nom1);
				break;

			case 4:
				printf("%s No Acertaste. Hazlo otra vez.", nom1);
				break;

			default:
				printf("\a\aERROR en el Sistema\nEste sms no se deberia de mostrar");
				break;
		}
	}
}


//Procedimiento
void preg(char o[1]){

	//Validacion solo se puede ingresar caracteres S - s - N - n
	while(o[0]!='S' && o[0]!='s' && o[0]!='N' && o[0]!='n'){

		printf("\nERROR, caracter no valido\n");
		printf("Desea finalizar (S/N): ");
		fflush(stdin);    //limpia el buffer
		scanf(" %c", &o[0]);
		while(getchar()!='\n'); 	//sirve para leer todos los caracteres antes de que enter sea presionado, tambien sirve como limpiador de buffer
	}
}