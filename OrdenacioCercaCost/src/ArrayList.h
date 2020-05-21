//
// Created by Sergi Vives on 21/5/2020.
//

#ifndef ORDENACIOCERCACOST_ARRAYLIST_H
#define ORDENACIOCERCACOST_ARRAYLIST_H

// Library includes
#include <stdbool.h>  // per a tractar booleans
#include <stdlib.h>  // Per a fer servir malloc
#include <stdio.h>  // per a fer servir la funcio printf en els jocs de proves
#include <limits.h>  // Per invoacar els imbols de INT_MIN

// DE includes
#include List.h

// Type defs
typedef struct ArrayList {
    unsigned int* array;
    unsigned int max_elements;
    unsigned int num_elements;
} ArrayList;

// Defines


#endif //ORDENACIOCERCACOST_ARRAYLIST_H
