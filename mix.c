/*
* mix.c
* Implements a MIX machine as described in "mix.h"
* Main program takes a MIX program to run from the command line.
* The MIX machine is initialized, and the program is ran (if possible).
*/
#include "mix.h"
#include "mix_opcodes.h"
#include <malloc.h>
#include <stdio.h>


/* MIX constant values. */

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

// Clear a machine half-word.
void clear_half_word(half_word_pt);

// Run MIX program.
int run(mix_pt, char*);


/* MIX backend function definitions. */

/*
* Startup initialization of a MIX machine.
* Sets condition and overflow bits, clears registers,
* and creates and initializes memory.
* param machine - MIX machine to initialize.
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
* param machine - MIX machine whos registers are to be initialized.
*/
void reg_init(mix_pt machine)
{
    printf("--Initializing registers...\n");

    // Clear the A and X word registers.
    clear_word(&machine->A);
    clear_word(&machine->X);

    // Clear the index registers.
    clear_index_regs(machine);

    // Clear the jump register.
    clear_half_word(&machine->J);
}


/*
* Clear a MIX machine word to +0.
* param w - Word to clear.
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
* param machine - MIX machine whos index registers are to be cleared.
*/
void clear_index_regs(mix_pt machine)
{
    clear_half_word(&machine->I1);
    clear_half_word(&machine->I2);
    clear_half_word(&machine->I3);
    clear_half_word(&machine->I4);
    clear_half_word(&machine->I5);
    clear_half_word(&machine->I6);
}


/*
* Clear a MIX machine half-word to +0.
* param hw - Half word clear.
*/
void clear_half_word(half_word_pt hw)
{
    hw->sign = PLUS;
    int i;
    for(i = 0; i < NUM_HALF_WORD_BYTES; ++i)
    {
        hw->byte[i] = 0;
    }
}


/*
* Initialize MIX memory.
* param machine - MIX machine whos memory is to be initialized.
*/
void mem_init(mix_pt machine)
{
    printf("--Initializing memory...\n");

    // Allocate MIX memory.
    machine->mem = (word_pt) calloc(MEM_SIZE, sizeof(word));
}


/*
* Release MIX memory.
* param machine - MIX machine to be shutdown.
*/
void shutdown(mix_pt machine)
{
    printf("Shutting down MIX machine...\n");

    // Free MIX memory.
    free(machine->mem);
}


/*
* Run the given program on the MIX machine given.
* param machine - MIX machine.
* param program - MIX program.
*/
int run(mix_pt machine, char* file)
{
    FILE* program;
    if(!(program = fopen(file, "r")))
    {
        printf("Unable to open file: %s", file);
        return -1;
    }
    printf("Running program %s...\n", file);
    fclose(program);
    return 0;
}


/*
* Main entry point into the program.
* Runs a MIX program file given in the command line arguments.
* param argc - Number of command line arguments.
* param argv - Command line arguments.
* Argument 0: This program's name (probably mix.exe).
* Argument 1: MIX program to run.
*/
int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Usage: expected a MIX machine program file name");
        return -1;
    }

    mix machine;
    startup_init(&machine);
    int result = run(&machine, argv[1]);
    shutdown(&machine);
    return result;
}

