build : test1.o test2.o
	gcc  test1-1.o test1-2.o -o run


test1.o : test1-1.c
	gcc -c test1-1.c -o test1.o


test2.o : test1-2.c
	gcc -c test1-2.c -o test2.o

clear :
	rm -rf run test1-1.o test1-2.o