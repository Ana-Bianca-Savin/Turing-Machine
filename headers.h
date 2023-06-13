//  SAVIN Ana-Bianca 314CB
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 20

// Pentru implementarea cozii

typedef struct celula {
    char* info;
    struct celula* urm;
} TCelula, *TLista;

typedef struct coada {
    TLista inc, sf;
} TCoada;

TCoada* InitQ();
int ExtrQ(TCoada*c, char **x);
int IntrQ(TCoada *c, char *x);
void DistrQ(TCoada **c);
void AfisareQ(TCoada *c);

// Pentru implementarea stivei

typedef struct stiCelula {
    void* poz;
    struct stiCelula* urm;
} TSCelula, *TStiva;

TLista AlocCelula(char *x);
void DistrugeLista(TLista* aL);
void AfisareLista(TLista L);
void Push(TStiva *aL, void *x);
void Pop(TStiva *aL, void **x);
void DistrugeStiva(TStiva* aL);
TStiva AlocCelulaStiva(void *x);
void AfisareStiva(TStiva L);

// Pentru implementarea listei dublu inlantuite cu santinela (banda)

typedef struct celula2 {
    char info;
    struct celula2 *pre, *urm;
} TCelula2, *TLista2;

typedef struct celula3 {
    TLista2 vf, deget;
} TBandaCelula, *TBanda;

TBanda InitBanda();
TLista2 AlocCelula2(char x);
TLista2 InitLista2();
TLista2 CitireLista2();
void AfisareLista2(TLista2 L);
void DistrugeLista2(TLista2 *aL);

// Pentru rezolvarea cerintei

void INSERT_RIGHT(TLista2 *L, char x);
void INSERT_LEFT(TLista2 *L, TLista2 *aL, char x, FILE *write);
void MOVE_LEFT(TLista2 *L, TLista2 *aL, TStiva *folosUNDO);
void MOVE_RIGHT(TLista2 *aL);
void WRITE(TLista2 *aL, char x);
void MOVE_LEFT_CHAR(TLista2 *L, TLista2 *aL, char x, FILE *write, TStiva *folosUNDO);
void MOVE_RIGHT_CHAR(TLista2 *aL, char x);
void SHOW_CURRENT(TLista2 aL, FILE *write);
void SHOW(TLista2 L, TLista2 aL, FILE *write);
void EXECUTE(TLista2 *L, TLista2 *aL, TCoada *c, TStiva *folosUNDO, FILE *write);
void UNDO(TStiva *folosUNDO, TStiva *folosREDO, TLista2 *L, TLista2 *aL);
void REDO(TStiva *folosUNDO, TStiva *folosREDO, TLista2 *L, TLista2 *aL);
