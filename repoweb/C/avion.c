#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE_ASIENTOS 10
 
int asignarAsiento(int [], int, int);
void pasaje(int);
void diagrama(int [], int);
 
main()
{
    srand(time(NULL));
    int asientos[SIZE_ASIENTOS] = {0};
    int i, num, cont = 0;
 
    printf("SISTEMA DE RESERVACION DE AEROLINEAS\n\n");
 
    diagrama(asientos, SIZE_ASIENTOS);
 
    while (cont <= SIZE_ASIENTOS - 1){
 
        printf("Por favor ingrese 1 para sector fumadores\n"
               "Por favor ingrese 2 para sector no fumadores\n");
        scanf("%d", &num);
 
        while (num > 2){
            printf("Numero no valido\n\n");
            printf("Por favor ingrese 1 para sector fumadores\n"
                   "Por favor ingrese 2 para sector no fumadores\n");
            scanf("%d", &num);
        }
 
        if ((asignarAsiento(asientos, SIZE_ASIENTOS, num)) != 0)
            cont++;
 
        diagrama(asientos, SIZE_ASIENTOS);
    }
 
    printf("Avion lleno\nProximo vuelo en 3 horas\n");
 
 
    return 0;
}
 
 
 
 
 
int asignarAsiento(int a[], int size, int n)
{
    char rta[1];
    int i, status = 0;
    static int cont1 = 0, cont2 = 0;
 
    switch(n){
        case 1:                     //SECTOR FUMADORES
            if (cont1 < size / 2){
                while (status == 0){
                    i = rand() % size /2;
                    if(a[i] == 0){
                        a[i] = 1;
                        pasaje(i);
                        cont1++;
                        status = 1;
                    }
                }
            }
            else{
                printf("La sección fumadores esta llena. "
                       "Le gustaria q le asignemos un lugar en la sección "
                       "de no fumadores(s/n)");
                scanf("%s", rta);
 
                if(rta[0] == 's' || rta[0] == 'S'){
                    while (status == 0){
                        i = size / 2 + rand() % size / 2;
                        if(a[i] == 0){
                            a[i] = 1;
                            pasaje(i);
                            cont2++;
                            status = 1;
                        }
                    }
                }
 
                else{
                    printf("\nEl proximo vuelo sale en 3 horas\n\n");
                    return 0;
                }
            }
 
            break;
 
 
        case 2:                     //SECTOR NO FUMADORES
            if (cont2 < size / 2){
                while (status == 0){
                    i = size / 2 + rand() % size / 2;
                    if (a[i] == 0){
                        a [i] = 1;
                        pasaje(i);
                        cont2++;
                        status = 1;
                    }
                }
            }
 
            else{
                printf("La sección de no fumadores esta llena. "
                       "Le gustaria q le asignemos un lugar en la sección "
                       "de fumadores(s/n)");
                scanf("%s", rta);
 
                if(rta[0] == 's' || rta[0] == 'S'){
                    while (status == 0){
                        i = rand() % size /2;
                        if(a[i] == 0){
                            a[i] = 1;
                            pasaje(i);
                            cont1++;
                            status = 1;
                        }
                    }
                }
 
                else{
                    printf("\nEl proximo vuelo sale en 3 horas\n\n");
                    return 0;
                }
            }
 
            break;
    }
 
}
 
void pasaje(int numAsiento)
{
    printf("\n************************\n");
    printf("AEROLINEA\n");
    printf("Pase de abordaje\n");
    if (numAsiento >= 0 && numAsiento <= 4){
        printf("Asiento nº %d\n", numAsiento + 1);
        printf("Sector fumadores\n");
    }
    else{
        printf("Asiento nº %d\n", numAsiento + 1);
        printf("Sector no fumadores\n");
    }
    printf("\n************************\n");
}
 
void diagrama(int a[], int size)
{
    int i;
 
    printf("\n");
    printf("%30s\n\n", "DIAGRAMA AVION");
    printf("%15s %26s\n", "FUMADORES", "NO FUMADORES");
    printf("/-------------------\\");
    printf("    /-------------------\\\n");
        for (i = 0; i <= size - 1; i++)
            printf("%-5d", a[i]);
    printf("\n\n");
 
}
 
 
