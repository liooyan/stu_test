objects = test1-1.o test1-2.o

build : ${objects}
	gcc  ${objects} -o run


test1-1.o  : test1-1.c



test1-2.o : test1-2.c


.PHONY : clean
clean :
	-rm  run ${objects}