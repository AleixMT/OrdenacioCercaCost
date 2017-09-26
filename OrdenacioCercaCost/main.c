#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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
int main()
{
    int v[N], cmpt;

    inicialitza(v);
    visualitza(v);
    getch();
}
