proj_name = tests

src_dir = ..

objs = test_field_spec_convert.o
src_objs = $(src_dir)/field_spec_convert.o

link = gcc -o $(proj_name)

compile = gcc -std=c11 -c


$(proj_name) : $(objs)
	$(link) $(objs) $(src_objs)

test_field_spec_convert.o : test_field_spec_convert.c
	$(compile) test_field_spec_convert.c

clean :
	rm $(objs) *.exe

