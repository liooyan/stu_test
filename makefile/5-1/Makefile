objects = test1.o test2.o


VPATH = ./ch/


#vpath %.c ./ch
build : ${objects}
	gcc  ${objects} -o run


test1.o  : test1.c



test2.o : test2.c


.PHONY : clean
clean :
	-rm  run ${objects}