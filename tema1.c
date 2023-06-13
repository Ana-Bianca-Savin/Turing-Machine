//  SAVIN Ana-Bianca 314CB
#include "headers.h"

int main() {
    // Initializare banda
    TBanda L = InitBanda();
    L->vf = InitLista2();
    L->deget = L->vf;
    INSERT_RIGHT(&L->deget, '#');

    // Initializare coada
    TCoada *c = InitQ();

    // Initializare stive UNDO si REDO
    TStiva folosUNDO = NULL;
    TStiva folosREDO = NULL;

    // Initializari si declarari generale
    FILE *read = fopen("tema1.in", "rt");
    FILE *write = fopen("tema1.out", "wt");
    int n = 0;
    char *str = calloc(MAX, sizeof(char));
    fscanf(read, "%d\n", &n);

    for (int i = 1; i <= n; i++) {
        fgets(str, MAX, read);
        if (str[strlen(str)-1] == '\n')
            str[strlen(str)-1] = '\0';

        if (strcmp(str, "SHOW") == 0)
            SHOW(L->vf, L->deget, write);
        else if (strcmp(str, "SHOW_CURRENT") == 0)
            SHOW_CURRENT(L->deget, write);
        else if (strcmp(str, "EXECUTE") == 0)
            EXECUTE(&L->vf, &L->deget, c, &folosUNDO, write);
        else if (strcmp(str, "UNDO") == 0)
            UNDO(&folosUNDO, &folosREDO, &L->vf, &L->deget);
        else if (strcmp(str, "REDO") == 0)
            REDO(&folosUNDO, &folosREDO, &L->vf, &L->deget);
        else
            IntrQ(c, str);
    }

    fclose(read);
    fclose(write);
    free(str);
    DistrugeLista2(&L->vf);
    free(L);
    DistrugeStiva(&folosUNDO);
    DistrugeStiva(&folosREDO);
    DistrQ(&c);
    return 0;
}
