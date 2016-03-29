/*
* assembler.c
* Assembles a MIXAL source file into MIX machine language.
*/
#include "token.h"
#include "lexer.h"
#include <stdio.h>


/*
* Assemble the given MIXAL source file into MIX machine language.
* Writes the machine code to a file with the same name,
* but with the extension ".o"
*/
void assemble(FILE* source)
{
    token tk;
}


/*
* Main entry point into the program.
* Takes a MIXAL source file and assembles it into MIX machine language.
* Param argc - Number of command line arguments.
* Param argv - Command line arguments.
* Argument 0: This programs name (probably assembler.exe)
* Argument 1: MIXAL source file to process.
*/
int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Usage: expected a MIXAL source file name\n");
        return -1;
    }
    FILE* source;
    if(!(source = fopen(argv[1], "r")))
    {
        printf("Unable to open MIXAL source file %s\n", argv[1]);
        return -1;
    }

    printf("Processing MIXAL source file %s...\n", argv[1]);
    assemble(source);
    fclose(source);
    return 0;
}