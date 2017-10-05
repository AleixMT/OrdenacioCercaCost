#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <conio.h>
#include <time.h>
#define N 20
#define NUM_ELEMENTS_ARRAY(x) (sizeof(x)/sizeof(x)[0]);


void ompleVectorAleatoriament (unsigned int v[], int midaVector)
{
    int i;
    srand(time(NULL));
    for (i=0; i<midaVector; i++){
        v[i] = rand()%(midaVector*100);
    }
}

void visualitza(unsigned int v[],int midaVector)
{
    int i;
    printf ("Vector amb %i elements\n", midaVector);
    for (i = 0; i < midaVector; i++)
    {
        printf("%d, ", v[i]);
    }
}

void swap(unsigned int v[], int i, int j){
    int a=v[i];
    v[i]=v[j];
    v[j]=a;
}

int bombolla (unsigned int v[], int midaVector){
    int i, cmpt=0;
    bool swapped = false;
    while (!swapped){
        for(i=1; i < midaVector; i++){
            if (v[i-1] > v[i]){
                swap(v, i-1, i);
                swapped = true;
            }
            cmpt++;
        }
         midaVector = midaVector-1;
    }
    return cmpt;
}

int selection_sort(unsigned int v[], int length){
    int j, i, cmpt=0;

    for (j = 0; j < length-1; j++){
        int iMin = j;
        for (i = j+1; i < length; i++) {
            if (v[i] < v[iMin])
            {
                iMin = i;
            }
            cmpt++;
        }
        if(iMin != j){
            swap(v, j, iMin);
        }
    }
    return cmpt;
}

int insercio()
{
    int cmpt=0;
    printf ("inxerxion");
    return cmpt;
}

int opcio ()
{
    int c=0;
    while (1){
    printf ("\nQuin algoritme vols fer servir?\n1.-Seleccio\n2.-Bombolla\n3.-Insercio\n\t\t->");
    c = getche();
    if (c < 49 || c > 51) printf ("\n\nOpció incorrecta, torna-ho a intentar...");
    else break;
    }
    printf ("%c", c);
    return (c - 47);
}

bool dicotomic_search(unsigned int v[], int lenght, int var){
    int inf=0;
    int sup=lenght-1;
    int cent;
    bool trobat=false;

    while(inf<=sup && !trobat){
        cent=(sup-inf)/2;
        if(v[cent]==var){
            trobat=true;
        }
        else{
            if(v[cent]>var){
                sup=cent;
            }
            else inf = cent;
        }
    }
    return trobat;
}

int main()
{
    unsigned int v[100], cmpt;
    int midaVector = NUM_ELEMENTS_ARRAY(v);


    cmpt = 0;
    ompleVectorAleatoriament(v, midaVector);
    visualitza(v, midaVector);
    switch (opcio())
    {
        case 1: cmpt = selection_sort(v, midaVector);
        case 2: cmpt = bombolla(v, midaVector);
        case 3: cmpt = insercio();
    }
    getch();
    visualitza(v, midaVector);
    return 0;
}
