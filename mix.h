/*
* mix.c
* Simulator of the MIX machine defined in Knuth, Volume 1, Section 1.3.1
* MIX:
* Byte - 6 bits or 2 decimal digits.
*   Must be capable of representing at least 64 unique values, and at most 100.
* Word - Machine word is a sign bit and 5 bytes.
* Registers:
*   A - Accumulator.
*       Consists of a sign, and 5 bytes. [S|a1|a2|a3|a4|a5]
*   X - Extension register.
*       Consists of a sign, and 5 bytes. [S|x1|x2|x3|x4|x5]
*   I - Index registers.
*       Consists of a sign, and 2 bytes. [S|i4|i5]
*       There are 6 index register [I1, I6].
*   J - Jump register.
*       Consists of a fixed sign (PLUS), and 2 bytes. [PLUS|j4|j5]
*   S - Sign bit, one of: PLUS (+) or MINUS (-).
*   C - Comparison indicator.
        Can take only the following values: LESS, EQUAL, GREATER.
*   O - Overflow indicator.
*       Can take on two values, NO_OVERFLOW, OVERFLOW
* Memory - 4000 words from [0, 3999].
*
* Half-word - Consists of a sign and 2 bytes.
* Note: This is not explicitly specified by Knuth.
*       The addition of a half word is for readability only.
*/
#ifndef MIX_MACHINE_H
#define MIX_MACHINE_H


#define NUM_WORD_BYTES 5
#define NUM_HALF_WORD_BYTES 2
#define NUM_INDEX_REGS 6

// Index locations of MIX machine instructions.
#define MIX_ADDR_1 0
#define MIX_ADDR_2 1
#define MIX_INDEX 2
#define MIX_OP_MOD 3
#define MIX_FIELD 3
#define MIX_OPCODE 4

// Machine byte.
#include "mix_byte.h"

// Machine word.
typedef struct _word
{
    mix_byte sign;
    mix_byte byte[NUM_WORD_BYTES];
} word, *word_pt;

// Machine half-word.
typedef struct _half_word
{
    mix_byte sign;
    mix_byte byte[NUM_HALF_WORD_BYTES];
} half_word, *half_word_pt;


// Mix machine.
typedef struct _mix
{
    // Program counter.
    word PC;

    // Accumulator.
    word A;

    // Extension register.
    word X;

    // Index resisters.
    half_word I1;
    half_word I2;
    half_word I3;
    half_word I4;
    half_word I5;
    half_word I6;

    // Jump registers.
    half_word J;

    // Condition bit.
    mix_byte condition;

    // Overflow bit.
    mix_byte overflow;

    // Memory.
    word_pt mem;

} mix, *mix_pt;

#endif
