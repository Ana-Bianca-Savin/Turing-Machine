//  SAVIN Ana-Bianca 314CB
#include "headers.h"

//  Aloca un element de tip TCelula2 si returneaza pointerul aferent
TLista2 AlocCelula2(char x) {
    TLista2 aux = (TLista2) malloc(sizeof(TCelula2));
    if (!aux) {
        return NULL;
    }

    aux->info = x;
    aux->pre = aux->urm = NULL;

    return aux;
}

//  Creeaza santinela pentru lista folosita
TLista2 InitLista2() {
    TLista2 aux = (TLista2) malloc(sizeof(TCelula2));
    if (!aux) {
        return NULL;
    }

    aux->info = 0;  //  informatia din santinela are valoarea 0
    aux->pre = NULL;
    aux->urm = NULL;

    return aux;
}

TBanda InitBanda() {
    TBanda aux = (TBanda) malloc(sizeof(TBandaCelula));
    if (!aux) {
        return NULL;
    }
    return aux;
}

//  Distrugere lista
void DistrugeLista2(TLista2 *aL) {
    TLista2 p = (*aL)->urm, aux = NULL;
    while (p != NULL) {
        aux = p;
        p = p->urm;
        free(aux);
    }

    free(*aL);
    *aL = NULL;
}
