objs = mix.o

compile = gcc -std=c11 -c
link = gcc -o mix

mix : $(objs)
	$(link) $(objs)

mix.o : mix.c mix.h mix_opcodes.h
	$(compile) mix.c

clean :
	rm $(objs) *.exe
