//
// Created by Sergi Vives on 21/5/2020.
//
#include "ArrayList.h"

int main(int argc, char *argv[]) {
	ArrayList *arrayList;
	create(&arrayList, 10);
	add(&arrayList, 6);
	add(&arrayList, 8);
	add(&arrayList, 7);
	add(&arrayList, 5);
	add(&arrayList, 5);
	add(&arrayList, 3);
	add(&arrayList, 3);
	add(&arrayList, 32323);
	add(&arrayList, 2);
	add(&arrayList, 4);



	for (unsigned int i = 0; i < 400; i += 23)
	{
		add(&arrayList, i);
	}

	printf("Get 0, 4, ultim llista: %u %u %u\n", get(*arrayList, 0), get(*arrayList, 4), get(*arrayList, arrayList->num_elements - 1));
	printf("%s", toString(*arrayList));

}