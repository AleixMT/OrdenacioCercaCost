#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define N 20


void inicialitza(int v[N])
{
    int i;
    srand(time(NULL));
    for (i = 0; i < N; i++) v[i] = (rand()%(N*100));
}

void visualitza(int v[N])
{
    int i;
    printf ("Vector amb %i elements\n", N);
    for (i = 0; i < N; i++)
    {
        printf("%i, ", v[i]);
    }
}

void seleccio()
{
    printf ("hoal tetis");
}

void bombolla()
{
    printf ("end of funccncncncnnntionn");
}

void insercio()
{
    printf ("inxerxion");
}

int opcio ()
{
    int c=0;
    while (1){
    printf ("\nQuin algoritme vols fer servir?\n1.-Selecció\n2.-Bombolla\n3.-Inserció\n\t\t->");
    c = getche();
    if (c < 49 || c > 51) printf ("\n\nOpció incorrecta, torna-ho a intentar...");
    else break;
    }
    return (c - 48);
}
int main()
{
    int v[N], cmpt;
    inicialitza(v);
    visualitza(v);
    switch (opcio())
    {
        case 1: seleccio();
        case 2: bombolla();
        case 3: insercio();
    }

    getch();
}
