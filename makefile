objs = mix.o field_spec_convert.o

compile = gcc -std=c11 -c
link = gcc -o mix

mix : $(objs)
	$(link) $(objs)

mix.o : mix.c mix.h mix_opcodes.h mix_byte.h
	$(compile) mix.c

field_spec_convert.o : field_spec_convert.c field_spec_convert.h mix_byte.h
	$(compile) field_spec_convert.c

clean :
	rm $(objs) *.exe
