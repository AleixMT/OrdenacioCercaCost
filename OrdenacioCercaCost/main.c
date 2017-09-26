#include <stdio.h>
#include <stdlib.h>
#define N 20



void inicialitza(unsigned int v[], int lenght)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < lenght; i++) v[i] = rand()%(lenght*100);
}

void visualitza(unsigned int v[], int lenght)
{
    int i;
    printf ("Vector amb %i elements\n", length);
    for (i = 0; i < length; i++)
    {
        printf("%d, ", v[i]);
    }
}

void swap(unsigned int v[], int i, int j){
    int a=v[i];
    v[i]=v[j];
    v[j]=a;
}

void selection_sort(unsigned int v[], int length){
    int j, i;

    for (j = 0; j < length-1; j++){
        int iMin = j;
        for (i = j+1; i < length; i++) {
            if (v[i] < v[iMin]) {
                iMin = i;
            }
        }
        if(iMin != j){
            swap(v[j], v[iMin]);
        }
    }

}


int main()
{
    unsigned int v[N];
    inicialitza(v, N);
    visualitza(v);
}
