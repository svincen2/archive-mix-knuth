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
*/
#ifndef MIX_MACHINE_H
#define MIX_MACHINE_H


#define NUM_WORD_BYTES 5
#define NUM_INDEX_REGS 6
#define INDEX_REG_SIZE 3

// Machine word.
typedef struct _word
{
    char sign;
    char byte[NUM_WORD_BYTES];
} word, *word_pt;


// Mix machine.
typedef struct _mix
{
    // Program counter.
    word PC;
    
    // Registers.
    word A;
    word X;
    char I1[INDEX_REG_SIZE];
    char I2[INDEX_REG_SIZE];
    char I3[INDEX_REG_SIZE];
    char I4[INDEX_REG_SIZE];
    char I5[INDEX_REG_SIZE];
    char I6[INDEX_REG_SIZE];
    char J[INDEX_REG_SIZE];

    // Condition bit.
    char cond;

    // Overflow bit.
    char overflow;

    // Memory.
    word_pt mem;

} mix, *mix_pt;

#endif
