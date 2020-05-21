//
// Created by Sergi Vives on 21/5/2020.
//

#ifndef ORDENACIOCERCACOST_LIST_H
#define ORDENACIOCERCACOST_LIST_H

// Headers
void create(ArrayList **arrayList);
void create(ArrayList **arrayList, unsigned int size);
void add(ArrayList **arrayList, unsigned int element);
unsigned int remove(ArrayList *arrayList);
unsigned int tail(ArrayList arrayList);
bool isEmpty(ArrayList arrayList);
bool ifFull(ArrayList arrayList);
bool destroy(ArrayList *arrayList);

#endif //ORDENACIOCERCACOST_LIST_H
