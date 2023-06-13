//  SAVIN Ana-Bianca 314CB
#include "headers.h"

//  Functii pentru coada

//  Initializeaza o coada
TCoada* InitQ() {
    TCoada* c = (TCoada*)malloc(sizeof(TCoada));
    if (!c)
        return NULL;
    c->inc = c->sf = NULL;
    return c;
}

//  Adauga element la sfarsitul cozii
int IntrQ(TCoada *c, char *x) {
    TLista aux = (TLista)malloc(sizeof(TCelula));
    if (!aux)
        return 0;
    aux->info = (char*)calloc(MAX, sizeof(char));
    if (!aux->info) {
        free(aux);
        return 0;
    }

    strncpy(aux->info, x, strlen(x));
    aux->urm = NULL;

    if (c->sf != NULL)
        c->sf->urm = aux;
    else
        c->inc = aux;
    c->sf = aux;
    return 1;
}

//  Extrage primul element din coada la adresa x
int ExtrQ(TCoada *c, char **x) {
    strncpy((*x), c->inc->info, strlen(c->inc->info));
    TLista aux = c->inc;
    c->inc = c->inc->urm;
    if (!c->inc)
        c->sf = NULL;
    free(aux->info);
    free(aux);
    return 1;
}

// Distruge coada
void DistrQ(TCoada **c) {
    TLista p = NULL, aux = NULL;
    p = (*c)->inc;
    while (p) {
        aux = p;
        p = p->urm;
        free(aux->info);
        free(aux);
    }
    free(*c);
    *c = NULL;
}

//  Functii pentru lista simplu inlantuita/stiva


//  Aloca o celula din lista
TLista AlocCelula(char *x) {
    TLista aux = (TLista) malloc(sizeof(TCelula));
    if (!aux)
        return NULL;
    aux->info = (char*)calloc(MAX, sizeof(char));
    if (!aux->info) {
        free(aux);
        return NULL;
    }

    strncpy(aux->info, x, strlen(x));
    aux->urm = NULL;
    return aux;
}

//  Distruge lista
void DistrugeLista(TLista* aL) {
    TLista aux = NULL;
    while (*aL) {
        aux = *aL;
        *aL = (*aL)->urm;
        free(aux->info);
        free(aux);
    }
}

//  Functii pentru stiva


//  Aloca o celula din lista
TStiva AlocCelulaStiva(void *x) {
    TStiva aux = (TStiva) malloc(sizeof(TSCelula));
    if (!aux)
    return NULL;

    aux->poz = x;
    aux->urm = NULL;
    return aux;
}

//  Distrugere stiva
void DistrugeStiva(TStiva* aL) {
    TStiva aux = NULL;
    while (*aL) {
        aux = *aL;
        *aL = (*aL)->urm;
        free(aux);
    }
}

//  Adauga un element la inceputul stivei
void Push(TStiva *aL, void *x) {
    TStiva aux = AlocCelulaStiva(x);
    if ((*aL) == NULL) {
        (*aL) = aux;
        return;
    }
    aux->urm  = (*aL);
    (*aL) = aux;
}

//  Extrage elementul de la inceputul stivei
void Pop(TStiva *aL, void **x) {
    if ((*aL) == NULL)
        return;
    (*x) = (*aL)->poz;
    TStiva aux = (*aL);
    (*aL) = (*aL)->urm;
    free(aux);
}
