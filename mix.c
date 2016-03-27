/*
* mix.c
* 
*/
#include "mix.h"
#include "mix_opcodes.h"
#include <malloc.h>
#include <stdio.h>


// MIX constant values.

// Sign bit possible values.
const char PLUS = 0;
const char MINUS = 1;

// Comparison possible values.
const char LESS = 0;
const char EQUAL = 1;
const char GREATER = 2;

// Overflow indicator possible values.
const char NO_OVERFLOW = 0;
const char OVERFLOW = 1;

// Memory size, in words.
const int MEM_SIZE = 4000;


/* Backend MIX function declarations. */

// Initialize machine state on startup.
void startup_init(mix_pt);

// Initialize machine registers.
void reg_init(mix_pt);

// Create and initialize memory.
void mem_init(mix_pt);

// Release memory.
void shutdown(mix_pt);

// Clear a machine word.
void clear_word(word_pt);

// Clear machine index registers.
void clear_index_regs(mix_pt);

// Clear an index register.
void clear_reg(char[INDEX_REG_SIZE]);

// Run MIX program.
void run(mix_pt, FILE*);


/* MIX backend function definitions. */

/*
* Startup initialization of a MIX machine.
* Sets condition and overflow bits, clears registers,
* and creates and initializes memory.
*/
void startup_init(mix_pt machine)
{
    printf("Starting MIX machine...\n");
    
    // Set the status bits for the comparison bit and overflow bit to:
    // EQUAL and NO_OVERFLOW, repectively.
    machine->cond = EQUAL;
    machine->overflow = NO_OVERFLOW;

    // Initialize registers to +0.
    reg_init(machine);

    // Create and initialize memory.
    mem_init(machine);
}


/*
* Register initialization of a MIX machine.
* Clears all registers to +0.
*/
void reg_init(mix_pt machine)
{
    printf("--Initializing registers...\n");
    
    clear_word(&machine->A);
    clear_word(&machine->X);
    clear_index_regs(machine);
    clear_reg(machine->J);
}


/*
* Clear a MIX machine word to +0.
*/
void clear_word(word_pt w)
{
    w->sign = PLUS;
    int i;
    for(i = 1; i < NUM_WORD_BYTES; ++i)
    {
        w->byte[i] = 0;
    }
}


/*
* Clear the index registers of a MIX machine.
*/
void clear_index_regs(mix_pt machine)
{
    clear_reg(machine->I1);
    clear_reg(machine->I2);
    clear_reg(machine->I3);
    clear_reg(machine->I4);
    clear_reg(machine->I5);
    clear_reg(machine->I6);
}


/*
* Clear a MIX 2 byte + sign register to +0.
*/
void clear_reg(char reg[INDEX_REG_SIZE])
{
    reg[0] = PLUS;
    int i;
    for(i = 1; i < INDEX_REG_SIZE; ++i)
    {
        reg[i] = 0;
    }
}


/*
* Initialize MIX memory.
*/
void mem_init(mix_pt machine)
{
    printf("--Initializing memory...\n");
    
    machine->mem = (word_pt) calloc(MEM_SIZE, sizeof(word));
}


/*
* Release MIX memory.
*/
void shutdown(mix_pt machine)
{
    printf("Shutting down MIX machine...\n");
    
    free(machine->mem);
}


/*
* Run the given program on the MIX machine given.
* Param machine - MIX machine.
* Param program - MIX program.
*/
void run(mix_pt machine, FILE* program)
{

}


/*
* Main entry point into the program.
* Runs a MIX program file given in the command line arguments.
* Param argc - Number of command line arguments.
* Param argv - Command line arguments.
* Argument 0: This program's name (probably mix.exe).
* Argument 1: MIX program to run.
*/
int main(int argc, char** argv)
{
    FILE* program;
    if(!(program = fopen(argv[1], "r")))
    {
        printf("Unable to open file: %s", argv[1]);
        return -1;
    }
    mix machine;
    startup_init(&machine);
    
    printf("Running program %s...\n", argv[1]);
    run(&machine, program);
    
    shutdown(&machine);
    fclose(program);
    return 0;
}
