#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>  // En entorns Unix aquesta llibreria no funciona i podem utilitzar la equivalent ncurses.h
#include <time.h>
#define N 20
#define NUM_REPETICIONS 10
#define NUM_ELEMENTS_ARRAY(x) (sizeof(x)/sizeof(x)[0]);


// Inicialitza seed i plena el vetor fins al final amb valors random
void ompleVectorAleatoriament (unsigned int v[], int midaVector)
{
    int i;
    srand(time(NULL));
    for (i=0; i<midaVector; i++){
        v[i] = rand()%(midaVector*100);
    }
}

//Imprimeix el vector per pantalla
void visualitza(unsigned int v[],int midaVector)
{
    int i;
    printf ("Vector amb %i elements\n", midaVector);
    for (i = 0; i < midaVector; i++)
    {
        printf("%d, ", v[i]);
    }
}

// Funció auxiliar per l'algoritme de bombolla i selection sort
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

// Cost quadràtic
int insercio(unsigned int v[], int length)
{
    int i, j, cmpt = 0, temp;
    time_t time();
    for (i = 1; i < length; i++)
    {
        temp = v[i];
        j = i - 1;
        while (v[j] > temp && j >= 0)
        {
            v[j+1] = v[j];
            j--;
            cmpt++;
        }
        v[j+1] = temp;
    }
    return cmpt;
}
void imprimeixMatriu(double m[][])
{
    printf("\n\n");
    printf ("*")
}
// Imprimeix per pantalla una matriu que relaciona el tipus d'algoritme utilitzat amb la mida del vector
// No utilitza el vector del main ja que per a fer less diferents proves hem de redefinir la mida del vector en temps d'execució
void mesures_temps()
{
    int mida_vector[] = {10, 50, 100, 500, 1000, 2000, 5000, 10000, 100000, 1000000}; // mida que tindra el vector a ordenar en cada una de les proves amb diferent mida
    int i, j, length_v;
    double acumulador;  // Acumula els segons al llarg de les repeticions per a fer la mitjana aritmetica
    int num_proves = NUM_ELEMENTS_ARRAY(mida_vector); // Obté el nombre de proves (nombre de files de la matriu de resultats mat_t)
    double mat_t[3][num_proves];    // matriu amb les mitjanes de temps amb el format descrit a la documentacio

    // Columna per a l'algoritme de bombolla
    for (j = 0; j < num_proves; j++)
    {
        unsigned int v[mida_vector[j]];
        length_v = NUM_ELEMENTS_ARRAY(v);
        for (i=0 ; i < NUM_REPETICIONS; i++)
        {
            ompleVectorAleatoriament(v, length_v);
            time_t t_ini = time(NULL);
            bombolla(v, length_v);
            time_t t_fin = time(NULL);
            acumulador += difftime(t_ini, t_fin);
        }
        mat_t[0][j] = acumulador/NUM_REPETICIONS;
    }

    // Columna per a l'algoritme de selecció
    for (j = 0; j < num_proves; j++)
    {
        unsigned int v[mida_vector[j]];
        length_v = NUM_ELEMENTS_ARRAY(v);
        for(i=0 ; i<NUM_REPETICIONS; i++)
        {
            ompleVectorAleatoriament(v, length_v);
            time_t t_ini = time(NULL);
            selection_sort(v, length_v);
            time_t t_fin = time(NULL);
            acumulador += difftime(t_ini, t_fin);
        }
        mat_t[1][j] = acumulador/NUM_REPETICIONS;
    }
    // Columna per a l'algoritme de bombolla
    for (j = 0; j < num_proves; j++)
    {
        unsigned int v[mida_vector[j]];
        length_v = NUM_ELEMENTS_ARRAY(v);
        for (i=0 ; i<NUM_REPETICIONS; i++)
        {
            ompleVectorAleatoriament(v, length_v);
            time_t t_ini = time(NULL);
            insercio(v, length_v);
            time_t t_fin = time(NULL);
            acumulador += difftime(t_ini, t_fin);
        }
        mat_t[2][j] = acumulador/NUM_REPETICIONS;
    }
    imprimeixMatriu(mat_t);
}
// Mostra el menu d'opcions i evita que l'usuari esculli una opcio incorrecta
int opcio ()
{
    int c=0;
    while (1){
    printf ("\nQuin algoritme vols fer servir?\n1.-Seleccio\n2.-Bombolla\n3.-Insercio\n\t\t->");
    c = getche();
    if (c < 49 || c > 51) printf ("\n\nOpció incorrecta, torna-ho a intentar...");
    else break;
    }
    return (c - 48);
}

// Cerca un valor dins del vector i retorna fals o cert segons si l'ha trobat
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
    unsigned int v[100], cmpt, valor;
    int midaVector = NUM_ELEMENTS_ARRAY(v);

    cmpt = 0;
    ompleVectorAleatoriament(v, midaVector);
    visualitza(v, midaVector);
    switch (opcio())
    {
        case 1: cmpt = selection_sort(v, midaVector); break;
        case 2: cmpt = bombolla(v, midaVector); break;
        case 3: cmpt = insercio(v, midaVector); break;
        case 4:
            printf("\nQuin valor vols buscar?\n");
            scanf("%i", &valor);
            dicotomic_search(v, midaVector, valor);
            break;
        case 5: mesures_temps(v, midaVector); break;
        case 6: mesures_cmpt(v, midaVector); break;
    }
    printf ("\n\n");
    visualitza(v, midaVector);
    getch();
    return 0;
}
