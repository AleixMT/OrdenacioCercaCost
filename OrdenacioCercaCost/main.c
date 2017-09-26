#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 20

int v[N];
void inicialitza()
{
    int i;
    srand(time(NULL));
    for (i = 0; i < N; i++) v[i] = rand();
}

void visualitza()
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
    inicialitza();
    visualitza();
    getch();
}
