#include "ArrayList.h"
#Include "List.h"

//
// Created by Sergi Vives on 14/4/20.
//

/*
 * PRIVATE FUNCTIONS
 */

/**
 * Auxiliar function for the bubble and selection sort algorithms.
 * @param array
 * @param i position of the first value
 * @param j position of the second value
 */
void swap(unsigned int array[], int i, int j){
    unsigned int a = array[i];
    array[i] = array[j];
    array[j] = a;
}

/*
 * PUBLIC FUNCTIONS
 */

/**
 * Reserves a certain amount of memory for the ArrayList and initializes its control data.
 * @param list pointer to ArrayList
 * @param size initial size of the ArrayList
 */
void create(ArrayList** arrayList, unsigned int size)
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
    (**arrayList).vector = malloc(sizeof(unsigned int) * size);
    if ((**arrayList).vector == NULL)
    {
        fprintf(stderr, "ERROR: Could not allocate memory for the array of ArrayList. Aborting... \n");
        exit(ERROR_CREATE);  // Abort program
    }

    (**ac).max_elements = size;
    (**ac).num_elements = 0;
}


/**
 * Reserves memory for the ArrayList and initializes its control data.
 * @param list pointer to ArrayList
 */
void create(ArrayList **arrayList)
{
    create(arrayList, 1);
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
        exit(ERROR_EMPTY_DE);  // Abort program
    }
    return arrayList.array[arrayList.num_elements - 1];
}


/**
 * Adds a new element to the ArrayList and reserves more memory if needed.
 * @param arrayList pointer to the ArrayList DE
 * @param element to add to the list
 */
void add(ArrayList **arrayList, unsigned int element)
{
    if (arrayList == NULL)
    {
        fprintf(stderr, "ERROR: Could not add element to an ArrayList. It does not exist. Aborting... \n");
        exit(ERROR_NONEXISTENT_DE);  // Abort the program
    }
    if (isEmpty(*arrayList))
    {
        //RF Realloc
        fprintf(stderr, "ERROR: Could not add element %i to the ArrayList. It is empty. Aborting... \n", element);
        exit(ERROR_FULL_DE);  // Abort the program
    }
    (*arrayList)->array[arrayList] = element;
    (*arrayList)->num_elementss++;
}

/**
 * Removes last element added to the ArrayList and returns it.
 * @param arrayList ArrayList DE
 * @return element at last position
 */
unsigned int remove(ArrayList *arrayList)
{
    if (arrayList == NULL)
    {
        fprintf(stderr, "ERROR: Could not remove last element of the ArrayList. It does not exist. Aborting... \n");
        exit(ERROR_NONEXISTENT_DE);  // Abort the program
    }
    if (isEmpty(*arrayList))
    {
        fprintf(stderr, "ERROR: Could not remove last element of the ArrayList. The ArrayList is empty. Aborting... \n");
        exit(ERROR_EMPTY_DE);  // Abort the program
    }
    arrayList->array[--arrayList->num_elements];
}

/**
 * Returns true if the ArrayList is empty. False otherwise.
 * @param arrayList ArrayList DE
 * @return
 */
bool isEmpty(ArrayList arrayList)
{
    return (arrayList.num_elements == 0);
}

/**
 * Returns true if the ArrayList is full. False otherwise.
 * @param arrayList ArrayList DE
 * @return
 */
bool isFull(ArrayList arrayList)
{
    return (arrayList.num_elements == arrayList.max_elements);
}

/**
 * Destroys the arrayList passed by reference and frees the used memory.
 * @param arrayList pointer to ArrayList DE
 */
void destroy(ArrayList *arrayList)
{
    if (arrayList == NULL)
    {
        fprintf(stderr, "ERROR: Could not destroy arrayList. The ArrayList does not exist. Aborting... \n");
        exit(ERROR_NONEXISTENT_DE);  // Abort the program
    }
    if (arrayList->array == NULL)
    {
        fprintf(stderr, "ERROR: Could not destroy arrayList. The array inside the ArrayList does not exist. Aborting... \n");
        exit(ERROR_NONEXISTENT_DE);  // Abort the program
    }
    free(ap->vector);  // Destroy array
    free(ap);  // Destroy DE
}
