objs = string_hash_map.o

compile = gcc -std=c11 -c


string_hash_map.o : string_hash_map.h string_hash_map.c
	$(compile) string_hash_map.c

clean :
	rm $(objs)

