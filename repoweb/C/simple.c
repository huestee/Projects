/*******************************************************************************
Author		:	Samuel Palma
Career		:	Ingenieria de Sistemas
Copyright	:	Todos los Derechos Reservados ©2019.
Description	:	Lista Simplemente Enlazada
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//------------------------------------------------------------------------------
typedef struct snodo{
	int items;
	struct snodo *next;
}tnodo;

typedef tnodo *pnodo;
typedef tnodo *list;

//----------------------------Prototipos de Funcion-----------------------------
void Menu();	//__Menu de Opciones__
char Option();	//__Ingresar una opcion del menu__
void SMSerror();	//__Muestra un sms de error__
void SMSbye();		//__Muestra un sms de despedida__
void SMSdelete(int);	//__Muestra un sms del numero eliminado__
void SMSposinvalida();//_Muestra un sms indicando la posicion ingresada invalida
void SMSemptylist();	//__Muestra un sms indicando que la lista esta vacia__
bool ListaVacia(list);	//__Verificar si la lista esta vacia o no__
int GetID();	//__Conseguir ID del Usuario__
int GetPosi();	//__Conseguir Posicion__
int Size(list);	//__Tamaño de la Lista__

//void CreateNodo(list *, int);	//__Insertar en la lista vacia__
void AddStart(list *, int);		//__Insertar al Inicio__
void AddEnd(list *, int);		//__Insertar al final__
void AddPosition(list *, int, int);		//__Insertar en cualquier posicion__
void DeleteStart(list *);	//__Retirar al Inicio__
void DeleteEnd(list *);	//__Retirar al Final__
void DeletePosition(list *, int);	//__Eliminar en cualquier posicion.__
void Delete(list *);	//__Retira todos los elementos de la lista.__
void Recover(list, int);	//__Recupera el Elemento Ubicado en X Posicion__
void SearchFor(list, int); //Localiza la Posicion Donde Esta Ubicado X Elemento_
void Order(list);	//__Ordena los Elementos de la Lista__
void Status(list);	//__Estado de Lista__

//------------------------------------------------------------------------------
main(){
	int data;	//__Datos__
	int posi;	//__Posicion__
	char opcion;	//__Opcion__
	
	list head=NULL;
	
	do{
		system("cls");
		Menu();		//__Menu de Opciones__
		opcion=Option();	//__Ingresar una opcion del menu__
		
		system("cls");
		switch(opcion){
			case '1':
				data=GetID();	//__Conseguir ID del Usuario__
				AddStart(&head, data);	//__Insertar al Inicio__
				break;
			case '2':
				data=GetID();	//__Conseguir ID del Usuario__
				AddEnd(&head, data);	//__Insertar al Final__
				break;
			case '3':
				data=GetID();	//__Conseguir ID del Usuario__
				posi=GetPosi();	//__Conseguir Posicion del Elemento__
				AddPosition(&head, data, posi);	//_InsertarEnCualquierPosiscion_
				break;
			case '4':
				DeleteStart(&head);	//__Retirar al Incio__
				break;
			case '5':
				DeleteEnd(&head);	//__Retirar al Final__
				break;
			case '6':
				if(ListaVacia(head))
					SMSemptylist();
				else{
					posi=GetPosi();	//__Conseguir Posicion del Elemento__
					DeletePosition(&head, posi); //_RetirarEnCualquierPosicion_
				}
				break;
			case '7':
				Delete(&head);	//__Retira todos los Elementos de la Lista__
				break;
			case '8':
				if(ListaVacia(head))
					SMSemptylist();
				else{
					posi=GetPosi();		//__Conseguir Posicion__
					Recover(head, posi);	//__Recupera el Elemento asignado __
				}						//__a X Posicion__
				break;
			case '9':
				if(ListaVacia(head))
					SMSemptylist();
				else{
					data=GetID();		//__Conseguir Dato__
					SearchFor(head, data);	//__Localiza la Posicion de__
				}							//__X Elemento__
				break;
			case 'a':
			case 'A':
				if(ListaVacia(head))
					SMSemptylist();
				else
					Order(head);			
				break;
			case 'b':
			case 'B':
				Status(head);	//__Muestra el Estado de la Lista__
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
/*******************************************************************************
-------------------------------Menu de Opciones---------------------------------
*******************************************************************************/
void Menu(){
	system("cls");
	printf("\n\t *************************************");
	printf("\n\t%c          Menu de la Lista           %c", 186, 186);
	printf("\n\t%c                                     %c", 186, 186);
	printf("\n\t%c  1. Insertar Elemento al Inicio     %c", 186, 186);
	printf("\n\t%c  2. Insertar Elemento al Final      %c", 186, 186);
	printf("\n\t%c  3. Insertar en Cualquier Posicion  %c", 186, 186);
	printf("\n\t%c  4. Retirar Primer Elemento         %c", 186, 186);
	printf("\n\t%c  5. Retirar Ultimo Elemento         %c", 186, 186);
	printf("\n\t%c  6. Retirar en Cualquier Posicion   %c", 186, 186);
	printf("\n\t%c  7. Retirar Todos los Elementos     %c", 186, 186);
	printf("\n\t%c  8. Recuperar Elemento              %c", 186, 186);
	printf("\n\t%c  9. Buscar o Localizar Elemento     %c", 186, 186);
	printf("\n\t%c  A. Ordenar ELementos               %c", 186, 186);
	printf("\n\t%c  B. Estado Actual de la Lista       %c", 186, 186);
	printf("\n\t%c  S. Salir del Programa              %c", 186, 186);
	printf("\n\t *************************************");
}

//------------------------------Elegir Opcion-----------------------------------
char Option(){
	char o;
	
	printf("\n\t\t *********************");
	printf("\n\t\t%c  Digite una Opcion  %c", 186, 186);
	printf("\n\t\t *********************");
	printf("\n\n\t\t\t*: ");
	fflush(stdin);
	scanf(" %c", &o);
	
	return o;
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
	printf("\n\n");
	printf("\t\t **********************");
	printf("\n\t\t%c   Hasta Luego    %c   %c", 186, 2, 186);
	printf("\n\t\t **********************");
	system("pause>nul");
}

//--------------------------SMS de Elemento Eliminado---------------------------
void SMSdelete(int elem){
	system("cls");
	printf("\n\n\t **********************");
	printf("\n\t%c  Elemento Eliminado  %c", 186, 186);
	printf("\n\t **********************");
	printf("\n\n\t\t*: %d", elem);
	system("pause>nul"); 
}

//-----------------------SMS de Posicion ingresada invalida---------------------
void SMSposinvalida(){
	system("cls");
	printf("\n\n");
	printf("\t\t ***********************************");
	printf("\n\t\t%c  ERROR, Posicion Invalida      X  %c", 186, 186);
	printf("\n\t\t ***********************************");
	system("pause>nul");
}

//-----------------------------SMS de Lista Vacia-------------------------------
void SMSemptylist(){
	printf("\n\n");
	printf("\t\t ****************");
	printf("\n\t\t%c  Lista Vacia   %c", 186, 186);
	printf("\n\t\t ****************");
	system("pause>nul");
}

/*******************************************************************************
----------------------------Conseguir ID----------------------------------------
*******************************************************************************/
int GetID(){
	int id;

	system("cls");
	printf("\n\n\t ***************");
	printf("\n\t%c  Ingrese ID  %c", 186, 186);
	printf("\n\t ***************");
	printf("\n\n\t\t*: ");
	scanf("%d", &id);

	return id;
}

//---------------------------Conseguir Posicion---------------------------------
int GetPosi(){
	int p;

	system("cls");
	printf("\n\n\t *********************");
	printf("\n\t%c  Ingrese Posicion  %c", 186, 186);
	printf("\n\t *********************");
	printf("\n\n\t*: ");
	scanf("%d", &p);

	return p;
}

//------------------------------Verificar Lista---------------------------------
bool ListaVacia(list head){
	if(head==NULL)
		return true;
	else
		return false;
}

//----------------------------Tamaño de la Lista--------------------------------
int Size(list head){
	int cont=0;
	
	pnodo aux=head;
	
	while(aux!=NULL){
		cont++;
		aux=aux->next;
	}
	
	return cont;
}

/*******************************************************************************
---------------------------Crear un Nodo----------------------------------------
*******************************************************************************/
/*void CreateNodo(list *head, int dato){
	pnodo nuevo=NULL;

	nuevo=(pnodo)malloc(sizeof(tnodo));

	if(nuevo!=NULL){
		nuevo->items=dato;
		nuevo->next=NULL;
		*head=nuevo;
	}
}*/

//----------------------------Insertar al Inicio--------------------------------
void AddStart(list *head, int dato){
	pnodo nuevo=NULL;

	nuevo=(pnodo)malloc(sizeof(tnodo));

	if(nuevo!=NULL){
		nuevo->items=dato;
		nuevo->next=*head;
		*head=nuevo;
	}
}

//---------------------------Insertar al Final----------------------------------
void AddEnd(list *head, int dato){
	pnodo nuevo=NULL;
	pnodo ultimo=*head;

	nuevo=(pnodo)malloc(sizeof(tnodo));

	if(nuevo!=NULL){
		nuevo->items=dato;
		nuevo->next=NULL;
		
		while(ultimo && ultimo->next!=NULL)
			ultimo=ultimo->next;

		ultimo->next=nuevo;
	}
}

//--------------------Insertar en Cualquier Posicion----------------------------
void AddPosition(list *head, int dato, int p){	//__ p -> Posicion __
	pnodo nuevo=NULL;
	
	nuevo=(pnodo)malloc(sizeof(tnodo));
	
	if(nuevo!=NULL){	
		nuevo->items=dato;
		nuevo->next=NULL;
		
		if(p==1)
			AddStart(head, dato);
		else if(p==Size(*head)+1)	
			AddEnd(head, dato);
		else if(p>1 && p<(Size(*head)+1)){
			pnodo back=NULL, front=*head;
			
			for(int i=1;i<p;i++){
				back=front;
				front=front->next;
			}
			
			back->next=nuevo;
			nuevo->next=front;			
		}
		else{
			//Manda un sms cuando se ingresa una posicion invalida
			SMSposinvalida();
		}
	}
}

//-----------------------------Retirar al Inicio--------------------------------
void DeleteStart(list *head){
	if(ListaVacia(*head))
		SMSemptylist();
	else{
		pnodo remove=*head;
		int temp=remove->items;	//__Almacena el dato a ser eliminado__
		
		SMSdelete(temp);	//_Muestra SMS del dato eleminado__
		
		*head=remove->next;
		free(remove);
	}
}

//----------------------------Retirar al Final----------------------------------
void DeleteEnd(list *head){
	if(ListaVacia(*head))
		SMSemptylist();
	else{
		pnodo remove=*head, ultimo=NULL;
		
		while(remove && remove->next!=NULL){
			ultimo=remove;
			remove=remove->next;
		}
		
		int temp=remove->items;	//__Almacena el dato a ser eliminado__
		SMSdelete(temp);	//_Muestra SMS del dato eleminado__
		
		ultimo->next=remove->next;	//__
		free(remove);
	}
}

//----------------------------Retirar en Cualquier Posicion---------------------
void DeletePosition(list *head, int p){	//__p -> Posicion__
	if(p==1)
		DeleteStart(head);
	else if(p==(Size(*head)))
		DeleteEnd(head);
	else if(p>1 && p<Size(*head)){
		pnodo back=NULL, front=*head;
		
		for(int i=1;i<p;i++){
			back=front;
			front=front->next;
		}			
		
		int temp=front->items;	//__Almacena el dato a ser eliminado__
		SMSdelete(temp);	//_Muestra SMS del dato eleminado__
		
		back->next=front->next;
		front->next=NULL;
		free(front);
	}
	else{
		//Manda un sms cuando se ingresa una posicion invalida
		SMSposinvalida();
	}
}

//--------------------------Retirar toda la Lista-------------------------------
void Delete(list *head){
	if(ListaVacia(*head))
		SMSemptylist();
	else{
		pnodo remove;
		
		while(*head!=NULL){
			remove=*head;
			*head=remove->next;
			free(remove);
		}
		
		if(ListaVacia(*head)){
			printf("\n\n");
			printf("\t\t**************************");
			printf("\n\t\t%c  Elementos Eliminados  %c", 186, 186);
			printf("\n\t\t**************************");
			system("pause>nul");
		}
		else{
			printf("\n\n");
			printf("\t\t ****************************************");
			printf("\n\n%c ERROR, nose deberia mostrar este SMS. %c");
			printf("\n\n\t ****************************************");
			system("pause>nul");
		}
	}
}

//-----------------------------Recuperar Elemento-------------------------------
void Recover(list head, int p){		//__ p -> Posicion __
	pnodo indice=head, aux=NULL;
	int temp=0;
	
	if(p>=1 && p<=Size(head)){
		/*while(indice!=NULL){
			aux=indice;
			if(i==p){
				temp=aux->items;
				break;
			}
			indice=indice->next;
			i++;
		}*/
		for(int i=1;i<=p;i++){
			aux=indice;
			indice=indice->next;
		}	
		temp=aux->items;
	}
	else{
		system("cls");
		printf("\n\n");
		printf("\t\t ***********************");
		printf("\n\t\t%c  Posicion No Existe  %c", 186, 186);
		printf("\n\t\t ***********************");
		system("pause>nul");
	}
	
	if(temp!=0){
		system("cls");
		printf("\n\n");
		printf("\t\t ***********************");
		printf("\n\t\t%c  Posicion Localizada  %c", 186, 186);
		printf("\n\t\t ***********************");
		printf("\n\t\t\t*Elemento: %d", temp);
		system("pause>nul");
	}
}

//-------------------------Busca o Localiza un Elemento-------------------------
void SearchFor(list head, int dato){
	int cont=1, temp=0;
	pnodo indice=head;
	
	while(indice!=NULL){
		
		if(indice->items==dato){
			temp=cont;
			break;
		}
		cont++;
		indice=indice->next;
	}
	
	if(temp!=0){
		system("cls");
		printf("\n\n");
		printf("\t\t ************************");
		printf("\n\t\t%c  Elemento Localizado  %c", 186, 186);
		printf("\n\t\t ************************");
		printf("\n\t\t\t*Posicion: %d", temp);
		system("pause>nul");
	}
	else{
		system("cls");
		printf("\n\n");
		printf("\t\t ***********************");
		printf("\n\t\t%c  Elemento No Existe  %c", 186, 186);
		printf("\n\t\t ***********************");
		system("pause>nul");
	}
}

//--------------------------Ordenacion de los Elementos-------------------------
void Order(list head){
	int temp;
	pnodo aux1=head, aux2=NULL;
	
	while(aux1!=NULL){
		aux2=aux1->next;
		while(aux2!=NULL){
			if(aux2->items<aux1->items){
				temp=aux1->items;
				aux1->items=aux2->items;
				aux2->items=temp;
			}
			aux2=aux2->next;
		}
		aux1=aux1->next;
	}
}

//----------------------------Estado de la Lista--------------------------------
void Status(list head){
	int cont=1;
	
	if(ListaVacia(head))
		SMSemptylist();
	else{
		pnodo indice=head;

		printf("\n\n\t**************************", 186, 186);
		printf("\n\t%c   Estado de la Lista   %c", 186, 186);
		printf("\n\t**************************\n", 186, 186);
		printf("\n\t\t     .______.\n");
		
		while(indice!=NULL){
			printf("\t\t%d.   %c__%d__%c\n", cont++, 186, indice->items, 186);
			indice=indice->next;
		}
		
		system("pause>nul");
	}
}
