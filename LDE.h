#include <stdio.h>
#include <stdlib.h>

typedef int TipoDato;

typedef struct nodo{
	TipoDato dato;
	struct nodo* ant;
	struct nodo* sig;
} NODO;

void insertarCabLDE(NODO **, TipoDato x);
void ingresarLDE(NODO *, TipoDato);
NODO *buscarLDE(NODO *, TipoDato);
void eliminarLDE(NODO **, TipoDato);
