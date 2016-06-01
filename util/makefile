objs = string_int_map.o

compile = gcc -std=c11 -c


string_int_map.o : string_int_map.h string_int_map.c
	$(compile) string_int_map.c

clean :
	rm $(objs)

