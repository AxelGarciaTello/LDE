#include "LDE.h"

void insertarCabLDE(NODO **cab, TipoDato x){
	NODO *nuevo=(NODO *) malloc(sizeof(NODO));
	nuevo->dato=x;
	nuevo->sig=*cab;
	nuevo->ant=NULL;
	if(*cab){
		(*cab)->ant=nuevo;
	}
	*cab=nuevo;
}

void ingresarLDE(NODO *anterior, TipoDato x){
	NODO *nuevo=(NODO *) malloc(sizeof(NODO));
	nuevo->dato=x;
	nuevo->sig=anterior->sig;
	anterior->sig=nuevo;
	nuevo->ant=anterior;
	nuevo->sig->ant=nuevo;
}

NODO *buscarLDE(NODO *cab, TipoDato x){
	if(cab!=NULL && cab->dato!=x){
		return buscarLDE(cab->sig, x);
	}
	return cab;
}

void eliminarLDE(NODO **cab, TipoDato x){
	NODO *actual=buscarLDE(*cab, x);
	if(actual!=NULL){
		if(actual==*cab){//Cabecera
			*cab=actual->sig;
			if(actual->sig!=NULL){
				actual->sig->ant=NULL;
			}
		}
		else if(actual->sig!=NULL){//Medio
			actual->sig->ant=actual->ant;
			actual->ant->sig=actual->sig;
		}
		else{//Final
			actual->ant->sig=NULL;
		}
		free(actual);
	}
}
