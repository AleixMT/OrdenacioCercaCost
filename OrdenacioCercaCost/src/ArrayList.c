#include "ArrayList.h"


//
// Created by Sergi Vives on 14/4/20.
//

/**
 * PROJECT SPECIFIC FUNCTIONS
 **/

// Inicialitza seed i plena el vetor fins al final amb valors random
void ompleVectorAleatoriament (unsigned int v[], int midaVector)
{
    int i;
    srand(time(NULL));
    for (i=0; i<midaVector; i++){
        v[i] = rand()%(midaVector*100);
    }
}

/*
 * PRIVATE FUNCTIONS
 */

/**
 * Auxiliar function for the bubble sort algorithms.
 * @param array
 * @param i position of the first value
 * @param j position of the second value
 */
void swap(unsigned int array[], int i, int j)
{
    unsigned int a = array[i];
    array[i] = array[j];
    array[j] = a;
}



/*
 * PUBLIC FUNCTIONS
 */

// BASIC ARRAYLIST FUNCTIONS
/**
 * Reserves a certain amount of memory for the ArrayList and initializes its control data.
 * @param list pointer to ArrayList
 * @param size initial size of the ArrayList
 */
void create(ArrayList **arrayList, unsigned int size)
{
    // Parameter checking
    if (size == 0)
    {
        fprintf(stderr, "ERROR: Could not create ArrayList. The size of the ArrayList has to be a natural number. Aborting... \n");
        exit(ERROR_BAD_PARAMETERS);  // Abort program
    }

    // Reserve memory for the data structure of the ArrayList
    *arrayList = (ArrayList*) malloc(sizeof(ArrayList));
    if (*arrayList == NULL)
    {
        fprintf(stderr, "ERROR: Could not allocate memory for ArrayList. Aborting... \n");
        exit(ERROR_CREATE);  // Abort program
    }

    // Reserve memory for the array of the ArrayList
    (**arrayList).array = malloc(sizeof(unsigned int) * size);
    if ((**arrayList).array == NULL)
    {
        fprintf(stderr, "ERROR: Could not allocate memory for the array of ArrayList. Aborting... \n");
        exit(ERROR_CREATE);  // Abort program
    }

    (**arrayList).max_elements = size;
    (**arrayList).num_elements = 0;
}


/**
 * Destroys the arrayList passed by reference and frees the used memory.
 * @param arrayList pointer to ArrayList
 */
bool destroy(ArrayList *arrayList)
{
    if (arrayList == NULL)
    {
        fprintf(stderr, "WARNING: Could not destroy arrayList. The ArrayList does not exist. Aborting... \n");
        return false;  // Abort the program
    }
    if (arrayList->array == NULL)
    {
        fprintf(stderr, "WARNING: Could not destroy arrayList. The array inside the ArrayList does not exist. Aborting... \n");
        return false;  // Abort the program
    }
    free(arrayList->array);  // Destroy array
    free(arrayList);  // Destroy DATA_STRUCTURE
    return true;
}


/**
 * Adds a new element to the ArrayList and reserves more memory if needed.
 * @param arrayList pointer to a pointer of the ArrayList 
 * @param element to add to the list
 */
void add(ArrayList **arrayList, unsigned int element)
{
    if (arrayList == NULL)
    {
        fprintf(stderr, "ERROR: Could not add element to an ArrayList. It does not exist. Aborting... \n");
        exit(ERROR_NONEXISTENT_DATA_STRUCTURE);  // Abort the program
    }
    if (isFull(**arrayList))
    {   
        // Duplicate size of the list 
        (**arrayList).max_elements = (**arrayList).max_elements * 2;
        (**arrayList).array = realloc((**arrayList).array, sizeof(unsigned int) * ((**arrayList).max_elements));

        if (*arrayList == NULL)
        {
            fprintf(stderr, "ERROR: Could not add element %i to the ArrayList. Memory is full. Aborting... \n", element);
            exit(ERROR_FULL_DATA_STRUCTURE);  // Abort the program
        }

    }
    (**arrayList).array[(**arrayList).num_elements] = element;
    (**arrayList).num_elements++;
}


/**
 * Gets the element at the specified index
 * @param arrayList ArrayList structure
 * @param index position of the list
 * @return array[position]
 **/
unsigned int get(ArrayList arrayList, unsigned int position)
{
    if (position >= arrayList.num_elements)
    {
        fprintf(stderr, "ERROR: Could not get element from ArrayList. Position is out of bounds. Aborting... \n");
        exit(ERROR_BAD_PARAMETERS);  // Abort the progra
    }
    return arrayList.array[position];
}


/**
 * Removes selected element from index position ArrayList and returns it.
 * @param arrayList ArrayList
 * @param position ArrayList
 * @return element at last position
 */
unsigned int pop(ArrayList *arrayList, unsigned int position)
{
    if (arrayList == NULL)
    {
        fprintf(stderr, "ERROR: Could not pop element from the ArrayList. The ArrayList does not exist. Aborting... \n");
        exit(ERROR_NONEXISTENT_DATA_STRUCTURE);  // Abort the program
    }
    if (isEmpty(*arrayList))
    {
        fprintf(stderr, "ERROR: Could not pop element from the ArrayList. The ArrayList is empty. Aborting... \n");
        exit(ERROR_EMPTY_DATA_STRUCTURE);  // Abort the program
    }
    if (position >= arrayList->num_elements)
    {
        fprintf(stderr, "ERROR: Could not pop element from the ArrayList. Position is out of bounds. Aborting... \n");
        exit(ERROR_BAD_PARAMETERS);  // Abort the progra
    }

    int elem = arrayList->array[position];  // make a temporal copy of the value
    arrayList->num_elements--;  // Substract one value from the list
    for (int i = position; i < arrayList->num_elements; i++)  // Move all elements a position
    {
        arrayList->array[i] = arrayList->array[i + 1]; 
    }
    return elem;
}


/**
 * Removes last element added to the ArrayList and returns it.
 * @param arrayList ArrayList
 * @return element at last position
 */
unsigned int removeLast(ArrayList *arrayList)
{
    if (arrayList == NULL)
    {
        fprintf(stderr, "ERROR: Could not remove last element of the ArrayList. It does not exist. Aborting... \n");
        exit(ERROR_NONEXISTENT_DATA_STRUCTURE);  // Abort the program
    }
    if (isEmpty(*arrayList))
    {
        fprintf(stderr, "ERROR: Could not remove last element of the ArrayList. The ArrayList is empty. Aborting... \n");
        exit(ERROR_EMPTY_DATA_STRUCTURE);  // Abort the program
    }
    return arrayList->array[--arrayList->num_elements];
}

/**
 * Returns last added element to the list.
 * @param list
 * @return
 */
unsigned int tail(ArrayList arrayList)
{
    if (isEmpty(arrayList))
    {
        fprintf(stderr, "ERROR: Could not return tail from an empty ArrayList. Aborting...\n");
        exit(ERROR_EMPTY_DATA_STRUCTURE);  // Abort program
    }
    return arrayList.array[arrayList.num_elements - 1];
}


/**
 * Returns true if the ArrayList is empty. False otherwise.
 * @param arrayList ArrayList
 * @return
 */
bool isEmpty(ArrayList arrayList)
{
    return (arrayList.num_elements == 0);
}


/**
 * Returns true if the ArrayList is full. False otherwise.
 * @param arrayList ArrayList
 * @return
 */
bool isFull(ArrayList arrayList)
{
    return (arrayList.num_elements == arrayList.max_elements);
}


/**
 * Converts the data structure to a string that contains at least the first and last 100 elements.
 * @param arrayList ArrayList
 **/
char* toString(ArrayList arrayList)
{
    char* msg = NULL;
    int offset = 0;
    if (arrayList.num_elements >= 200)
    {
        msg = (char *) malloc(sizeof(char) * 200 * (1 + 10) + 5 + 1);
        for (int i = 0; i < 200; i++)
        {
            offset += sprintf(&(msg[offset]), "%d ", arrayList.array[i]);
        }
        offset += sprintf(&(msg[offset]), "\n...\n");
        for (int i = arrayList.num_elements - 100; i < arrayList.num_elements; i++)
        {
            offset += sprintf(&(msg[offset]), "%d ", arrayList.array[i]);
        }
    }
    else
    {
        msg = (char *) malloc(sizeof(char) * arrayList.num_elements * 2 + 1);
        for (int i = 0; i < arrayList.num_elements; i++)
        {
            offset += sprintf(&(msg[offset]), "%d ", arrayList.array[i]);
        }

    }
    return msg;
}

