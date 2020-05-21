//
// Created by Sergi Vives on 21/5/2020.
//

#ifndef ORDENACIOCERCACOST_ARRAYLIST_H
#define ORDENACIOCERCACOST_ARRAYLIST_H

// Library includes
#include <stdbool.h>  // To use boolean types
#include <stdlib.h>  // To use malloc, realloc and free
#include <stdio.h>  // To use printf and file manipulation functions
#include <limits.h>  // To use datatype sumbols such as INT_MIN
#include <string.h>  // To use the String library

// Project includes
#include "ErrorCodes.h"

// Class defines
#define N 100000  // Max number of elements 10 ^ 5

// Type defs
typedef struct ArrayList {
    unsigned int* array;
    unsigned int max_elements;
    unsigned int num_elements;
} ArrayList;

// Function headers
// Basic functions
void create(ArrayList **arrayList, unsigned int size);
bool destroy(ArrayList *arrayList);
bool isEmpty(ArrayList arrayList);
bool isFull(ArrayList arrayList);
void add(ArrayList **arrayList, unsigned int element);
unsigned int get(ArrayList arrayList, unsigned int position);
unsigned int pop(ArrayList *arrayList, unsigned int position);

// Decorators
unsigned int removeLast(ArrayList *arrayList);
unsigned int tail(ArrayList arrayList);

// Specific project functions
char* toString(ArrayList arrayList);

#endif //ORDENACIOCERCACOST_ARRAYLIST_H
