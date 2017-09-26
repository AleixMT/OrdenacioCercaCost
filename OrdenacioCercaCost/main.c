#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#define NUM_ELEMENTS_ARRAY(x) (sizeof(x)/sizeof(x)[0]));

void ompleVectorAleatoriament (unsigned int v[], int midaVector){
        int i;
        srand(time(NULL));
        for (i=0; i<midaVector; i++){
             v[i] = rand()%(midaVector*100);
        }
}

void bombolla (unsigned int v[], int midaVector){
    int i;
    bool swapped = false;
    while (!swapped){
        for(i=1; i<midaVector; i++){
            if (v[i-1] > v[i]){
                swap(v[i-1], v[i]);
                swapped = true;
            }
        }
         midaVector = midaVector-1;
    }
}

void swap(unsigned int *i, unsigned int *j){
    int temp;

    temp = *i;
    *i=*j;
    *j=temp;
}

void visualitza(unsigned int v[],int midaVector)
{
    int i;
    printf ("Vector amb %i elements\n", midaVector);
    for (i = 0; i < midaVector; i++)
    {
        printf("%i, ", v[i]);
    }
}

int main()
{
    unsigned int v[100000];
    int cmpt, midaVector = NUM_ELEMENTS_ARRAY(v);

    ompleVectorAleatoriament(v, midaVector);
    visualitza(v, midaVector);
    getch();

    return 0;
}
