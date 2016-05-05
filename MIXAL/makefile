proj_name = assembler

objs = token.o lexer.o assembler.o

compile = gcc -std=c11 -c
link = gcc -o $(proj_name)

assembler : $(objs)
	$(link) $(objs)

assembler.o : assembler.c lexer.h token.h
	$(compile) assembler.c

lexer.o : lexer.c lexer.h token.h
	$(compile) lexer.c

token.o : token.c token.h
	$(compile) token.c

clean :
	rm $(objs) *.exe
