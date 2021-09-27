objc = $(wildcard *.c)

objects = $(objc:%.c=%.o)

build : ${objects}
	gcc  ${objects} -o run



.PHONY : clean
clean :
	-rm  run $(objects)