//-------------------------------Funcion Calloc------------------------------
#include<stdio.h>
#include<stdlib.h>

int main(){
	char *c;
	int *entero;
	float *flotante;
	double *doble;

	c=(char *)calloc(1,1);
	entero=(int *)calloc(1,4);
	flotante=(float *)calloc(1,4);
	doble=(double *)calloc(1,8);

	*c='a';
	*entero=10;
	*flotante=3.89172376;
	*doble=1.48263;

	system("cls");

	printf("\n\tValores\nCaracter %c\nEntero %d", *c, *entero);
	printf("\nFlotante %f\nDoble %lf", *flotante, *doble);

	//____Importantisimo liberar la memoria cuando ya no es requerida_____
	free(c);
	free(entero);
	free(flotante);
	free(doble);

	system("pause");

	return 0;
}