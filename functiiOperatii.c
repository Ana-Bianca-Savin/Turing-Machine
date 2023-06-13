//  SAVIN Ana-Bianca 314CB
#include "headers.h"

//  UPDATE

void WRITE(TLista2 *deget, char x) {
    (*deget)->info = x;
}

void MOVE_LEFT(TLista2 *L, TLista2 *deget, TStiva *folosUNDO) {
    if ((*deget)->pre == (*L)) {
        void *aux = NULL;
        Pop(folosUNDO, &aux);
        return;
    }
    (*deget) = (*deget)->pre;
}

void MOVE_RIGHT(TLista2 *deget) {
    if ((*deget)->urm == NULL) {
        INSERT_RIGHT(deget, '#');
        return;
    }
    (*deget) = (*deget)->urm;
}

void INSERT_RIGHT(TLista2 *deget, char x) {
    TLista2 aux = AlocCelula2(x);

    if ((*deget)->urm == NULL) {
        aux->pre = (*deget);
        (*deget)->urm = aux;
        aux->urm = NULL;
    } else {
        aux->pre = (*deget);
        aux->urm = (*deget)->urm;
        (*deget)->urm = aux;
        aux->urm->pre = aux;
    }

    (*deget) = (*deget)->urm;
}

void INSERT_LEFT(TLista2 *L, TLista2 *deget, char x, FILE *write) {
    if ((*deget)->pre == (*L)) {
        fprintf(write, "ERROR\n");
        return;
    }
    TLista2 aux = AlocCelula2(x);
    aux->urm = (*deget);
    aux->pre = (*deget)->pre;
    (*deget)->pre->urm = aux;
    (*deget)->pre = aux;

    (*deget) = (*deget)->pre;
}

void MOVE_LEFT_CHAR(TLista2 *L, TLista2 *deget, char x, FILE *write, TStiva *folosUNDO) {
    TLista2 aux = (*deget);

    while (aux != (*L)) {
        if (aux->info == x) {
            (*deget) = aux;
            return;
        }
        aux = aux->pre;
    }
    /*
    void *aux2 = NULL;
    Pop(folosUNDO, &aux2);
    */
    fprintf(write, "ERROR\n");
}

void MOVE_RIGHT_CHAR(TLista2 *deget, char x) {
    TLista2 aux = (*deget);

    while (aux->urm != NULL) {
        if (aux->info == x) {
            (*deget) = aux;
            return;
        }
        aux = aux->urm;
    }
    if (aux->info == x) {
        (*deget) = aux;
        return;
    }
    (*deget) = aux;
    INSERT_RIGHT(deget, '#');
}

//  QUERY

void SHOW_CURRENT(TLista2 deget, FILE *write) {
    fprintf(write, "%c\n", deget->info);
}

void SHOW(TLista2 L, TLista2 deget, FILE *write) {
    TLista2 aux = L->urm;

    while (aux) {
        if (aux == deget)
            fprintf(write, "|%c|", aux->info);
        else
            fprintf(write, "%c", aux->info);
        aux = aux->urm;
    }
    fprintf(write, "\n");
}

//  UNDO / REDO
void UNDO(TStiva *folosUNDO, TStiva *folosREDO, TLista2 *L, TLista2 *deget) {
    void *aux = NULL;
    Push(folosREDO, *deget);
    Pop(folosUNDO, &aux);
    (*deget) = aux;
}

void REDO(TStiva *folosUNDO, TStiva *folosREDO, TLista2 *L, TLista2 *deget) {
    void *aux = NULL;
    Push(folosUNDO, *deget);
    Pop(folosREDO, &aux);
    (*deget) = aux;
}

//  EXECUTE

void EXECUTE(TLista2 *L, TLista2 *deget, TCoada *c, TStiva *folosUNDO, FILE *write) {
    char *str = calloc(MAX, sizeof(char));
    if (!str)
        return;
    ExtrQ(c, &str);

    if (strcmp(str, "MOVE_RIGHT") == 0) {
        Push(folosUNDO, *deget);
        MOVE_RIGHT(deget);
    } else if (strcmp(str, "MOVE_LEFT") == 0) {
        Push(folosUNDO, *deget);
        MOVE_LEFT(L, deget, folosUNDO);
    } else if (strstr(str, "MOVE_RIGHT_CHAR")) {
        // Push(folosUNDO, *deget);
        char character = str[strlen(str)-1];
        MOVE_RIGHT_CHAR(deget, character);
    } else if (strstr(str, "MOVE_LEFT_CHAR")) {
        // Push(folosUNDO, *deget);
        char character = str[strlen(str)-1];
        MOVE_LEFT_CHAR(L, deget, character, write, folosUNDO);
    } else if (strstr(str, "WRITE") != NULL) {
        char character = str[strlen(str)-1];
        WRITE(deget, character);
    } else if (strstr(str, "INSERT_RIGHT")) {
        char character = str[strlen(str)-1];
        INSERT_RIGHT(deget, character);
    } else if (strstr(str, "INSERT_LEFT")) {
        char character = str[strlen(str)-1];
        INSERT_LEFT(L, deget, character, write);
    }

    free(str);
}
