CC = gcc
CFLAGS = -O3 -Wall

all : ArrayList ArrayListTest

ArrayList : ArrayList.c ArrayListTest.c
	$(CC) $(CFLAGS) ArrayList.c ArrayListTest.c -o test

run : test
	./test

.PHONY : clean
clean :
	rm -f test
