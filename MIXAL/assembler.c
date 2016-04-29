/*
* assembler.c
* Assembles a MIXAL source file into MIX machine language.
*/
#include "token.h"
#include "lexer.h"
#include <stdlib.h>
#include <stdio.h>


/*
* Attempts to open the file with the given name.
* param file - Name of the file to open.
* return - Pointer to the open file.
*/
FILE* open_file(char* file)
{
    FILE* source;
    if(!(source = fopen(file, "r")))
    {
        printf("Unable to open MIXAL source file %s\nExiting...", file);
        exit(-1);
    }
    return source;
}


/*
* Assemble the given MIXAL source file into MIX machine language.
* Writes the machine code to a file with the same name,
* but with the extension ".o"
* param file - Name of the file to assemble.
*/
void assemble(char* file)
{
    FILE* source = open_file(file);
    printf("Processing MIXAL source file %s...\n", file);
    token tk;
}


/*
* Main entry point into the program.
* Takes a MIXAL source file and assembles it into MIX machine language.
* param argc - Number of command line arguments.
* param argv - Command line arguments.
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
    assemble(argv[1]);
    return 0;
}

