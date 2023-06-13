# Implementare

Pentru implementarea benzii am folosit o lista dublu inlantuita cu santinela, asa cum era precizat in cerinta. Am luat scheletul de cod pentru acest tip de lista de la laborator si am modificat structura astfel incat informatia sa fie de tip char. Apoi, am definit o structura TBanda care are doua elemente de tipul listei descrisa mai sus, vf care reprezinta varful listei si deget care reprezinta adresa catre pozitia degetului.
Pentru implementarea cozii am ales sa folosesc o lista simplu inlantuita si am folosit scheletul de cod de la laborator pentru coada, informatia din structura fiind de tip char*.
Pentru implementarea stivei  am ales sa folosesc o lista simplu inlantuita cu informatia de tip void*. Am scris functiile de alocare celula, distrugere, functia push care insereaza un element in varful stivei si functia pop care extrage elementul din varful stivei.
Structurile si headere-le functiilor se gasesc in fisierul headers.h, iar functiile pentru coada si stiva sunt in fisierul functiiCoadaStiva.c, functiile pentru banda sunt in functiiBanda, functiile pentru efectuarea actiunilor descrise in cerinta sunt in functiiOperatii.h.


# Program principal tema1.c

Initializez banda L, cu ajutorul functiilor din schelet. Pointerul catre deget este initializat cu adresa caracterului #, singurul caracter care se afla initial pe banda.
Initializez o coada c in care sunt retinute operatiile de tip UPDATE care se vor executa la intalnirea instructiunii EXECUTE.
Initializez cu NULL doua stive folosUNDO si folosREDO. In stiva folosUNDO sunt adaugate in varf operatiile asupra carora se poate aplica operatia UNDO. In stiva folosREDO sunt adaugate in varf operatiile asupra carora li s-a aplicat operatia UNDO si acum se poate aplica REDO.
Se citeste din fisierul tema1.in valoarea n, reprezentand numarul de instructiuni. Apoi se citeste pe rand fiecare operatie. Daca este de tipul UPDATE se adauga la coada, daca este de tipul QUERRY si UNDO sau REDO se apeleaza functia corespunzatoare, iar daca este EXECUTE se apeleaza functia cu acelasi nume.
La final, se inchid fisierele de citire si scriere si se fac dezalocari pentru toate listele si pentru string-ul folosit la citire.


# Operatii de tip UPDATE

Functia WRITE primeste ca parametru un pointer la pozitia degetului si un char. Aceasta modifica informatia de la pozitia degetului in cea primita prin parametrul char.
Functia MOVE_RIGHT primeste ca parametru un pointer la pozitia degetului. Daca urmatoarea pozitie este nula, se apeleaza functia INSERT_RIGHT pentru a insera caracterul # la finalul benzii. Altfel, degetul este mutat la urmatoarea adresa din lista.
Functia MOVE_LEFT primeste ca parametru in plus fata de MOVE_RIGHT si un pointer catre varful listei si un pointer catre varful stivei folosUNDO ce este folosita pentru a retine comenzile folosite asupra carora se poate efectual operatia UNDO. Daca adresa de inaintea degetului corespunde cu cea a sentinelei, atunci trebuie sa apelam functia Pop ca sa extragem din folosUNDO actiunea comenzii MOVE_LEFT din moment ce aceasta nu este valida.
Functia INSERT_RIGHT aloca o noua celula cu informatia primita prin parametru. Apoi o insereaza la adresa urmatoare dupa adresa degetului. Daca urmatoarea adresa este nula, atunci se vor realiza doar legaturile cu celula pe care se afla degetul. Daca nu, se vor realiza si legaturile cu celula urmatoare. La final, adresa degetului devine adresa urmatoare.
Functia INSERT_LEFT verifica daca celula anterioara degetului este nula si in caz afirmativ afiseaza mesajul "ERROR". Altfel se realizeaza legaturile corespunzatoare, si se muta adresa degetului la pozitia anterioara.
Functia MOVE_RIGHT_CHAR parcurge lista in dreapta de la adresa degetului si schimba adresa degetului cu cea a celulei cu informatia corespunzatoare. Daca nu este gasit caracterul, se apeleaza functia INSERT_RIGHT pentru a insera # la finalul benzii.
Functia MOVE_LEFT_CHAR parcurge lista in stanga de la adresa degetului si daca este gasit caracterul schimba adresa degetului cu cea a celulei cu informatia corespunzatoare.


# Operatii de tip QUERRY

Functia SHOW_CURRENT afiseaza informatia de la adresa degetului, primit ca parametru.
Functia SHOW parcurge elementele din toata banda in ordine. Daca adresa elementului curect corespunde cu cea a degetului, informatia este afisata intre doua caractere | , iar daca nu sunt afisate normal.


# Operatii de tip UNDO / REDO

Functia UNDO adauga pointerul la pozitia curenta a degetului in stiva folosREDO, extrage din varful stivei folosUNDO pointerul, iar adresa degetului ia valoarea acestuia.
Functia REDO adauga pointerul la pozitia curenta a degetului in stiva folosUNDO, extrage din varful stivei folosREDO pointerul, iar adresa degetului ia valoarea acestuia.


# Operatia EXECUTE

Functia EXECUTE extrage mai intai string-ul din varful cozii. Compara acest string cu string-uri sugestive, pentru a determina ce functie trebuie apelata. Pentru functiile MOVE_LEFT_CHAR, MOVE_RIGHT_CHAR, INSERT_RIGHT si INSERT_LEFT, se va extrage caracterul aflat in string-ul extras si va fi folosit la apelul functiei respective. Daca functia apelata este MOVE_RIGHT sau MOVE_LEFT, se va da push in folosUNDO la adresa degetului inainte de a se apela functia respectiva.
