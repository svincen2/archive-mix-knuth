/*
* mix_opcodes.h
* Operation codes for the MIX machine,
* as defined by Knuth in Volume 1, Section 1.3.1
* Defines the 'C' value for each op code (see Knuth).
*/
#ifndef MIX_OPCODES_H
#define MIX_OPCODES_H


// Load operators.
#define LDA 8
#define LD1 9
#define LD2 10
#define LD3 11
#define LD4 12
#define LD5 13
#define LD6 14
#define LDX 15
#define LDAN 16
#define LD1N 17
#define LD2N 18
#define LD3N 19
#define LD4N 20
#define LD5N 21
#define LD6N 22
#define LDXN 23

// Store operators.
#define STA 24
#define ST1 25
#define ST2 26
#define ST3 27
#define ST4 28
#define ST5 29
#define ST6 30
#define STX 31
#define STJ 32
#define STZ 33

// Arithmetic operators.
#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4

// Address transfer operators.
#define ENTA 48     #define ENT_F 2 // F = 2.
#define ENT1 49
#define ENT2 50
#define ENT3 51
#define ENT4 52
#define ENT5 53
#define ENT6 54
#define ENTX 55

#define ENNA ENTA   #define ENN_F 3 // F = 3.
#define ENNX ENTX
#define ENN1 ENT1
#define ENN2 ENT2
#define ENN3 ENT3
#define ENN4 ENT4
#define ENN5 ENT5
#define ENN6 ENT6

#define INCA ENTA   #define INC_F 0 // F = 0.
#define INCX ENTX
#define INC1 ENT1
#define INC2 ENT2
#define INC3 ENT3
#define INC4 ENT4
#define INC5 ENT5
#define INC6 ENT6

#define DECA ENTA   #define DEC_F 1 // F = 1.
#define DECX ENTX
#define DEC1 ENT1
#define DEC2 ENT2
#define DEC3 ENT3
#define DEC4 ENT4
#define DEC5 ENT5
#define DEC6 ENT6

// Comparison operators.
#define CMPA 56
#define CMP1 57
#define CMP2 58
#define CMP3 59
#define CMP4 60
#define CMP5 61
#define CMP6 62
#define CMPX 63

// Jump operators.
#define JMP 39      #define JMP_F 0     // F = 0.
#define JSJ JMP     #define JSJ_F 1     // F = 1.
#define JOV JMP     #define JOV_F 2     // F = 2.
#define JNOV JMP    #define JNOV_F 3    // F = 3.
#define JL JMP      #define JL_F 4      // F = 4.
#define JE JMP      #define JE_F 5      // F = 5.
#define JG JMP      #define JG_F 6      // F = 6.
#define JGE JMP     #define JGE_F 7     // F = 7.
#define JNE JMP     #define JNE_F 8     // F = 8.
#define JLE JMP     #define JLE_F 9     // F = 9.

#define JAN 40      #define JAN_F 0     // F = 0.
#define JAZ JAN     #define JAZ_F 1     // F = 1.
#define JAP JAN     #define JAP_F 2     // F = 2.
#define JANN JAN    #define JANN_F 3    // F = 3.
#define JANZ JAN    #define JANZ_F 4    // F = 4.
#define JANP JAN    #define JANP_F 5    // F = 5.

#define JXN 47      #define JXN_F 0     // F = 0.
#define JXZ JXN     #define JXZ_F 1     // F = 1.
#define JXP JXN     #define JXP_F 2     // F = 2.
#define JXNN JXN    #define JXNN_F 3    // F = 3.
#define JXNZ JXN    #define JXNZ_F 4    // F = 4.
#define JXNP JXN    #define JXNZ_P 5    // F = 5.

#define J1N 41      #define J1N_F 0     // F = 0.
#define J1Z J1N     #define J1Z_F 1     // F = 1.
#define J1P J1N     #define J1P_F 2     // F = 2.
#define J1NN J1N    #define J1NN_F 3    // F = 3.
#define J1NZ J1N    #define J1NZ_F 4    // F = 4.
#define J1NP J1N    #define J1NP_F 5    // F = 5.

#define J2N 42      #define J2N_F 0     // F = 0.
#define J2Z J2N     #define J2Z_F 1     // F = 0.
#define J2P J2N     #define J2P_F 2     // F = 2.
#define J2NN J2N    #define J2NN_F 3    // F = 3.
#define J2NZ J2N    #define J2NZ_F 4    // F = 4.
#define J2NP J2N    #define J2NP_F 5    // F = 5.

#define J3N 43      #define J3N_F 0     // F = 0.
#define J3Z J3N     #define J3Z_F 1     // F = 1.
#define J3P J3N     #define J3P_F 2     // F = 2.
#define J3NN J3N    #define J3NN_F 3    // F = 3.
#define J3NZ J3N    #define J3NZ_F 4    // F = 4.
#define J3NP J3N    #define J3NP_F 5    // F = 5.

#define J4N 44      #define J4N_F 0     // F = 0.
#define J4Z J4N     #define J4Z_F 1     // F = 1.
#define J4P J4N     #define J4P_F 2     // F = 2.
#define J4NN J4N    #define J4NN_F 3    // F = 3.
#define J4NZ J4N    #define J4NZ_F 4    // F = 4.
#define J4NP J4N    #define J4NP_F 5    // F = 5.

#define J5N 45      #define J5N_F 0     // F = 0.
#define J5Z J5N     #define J5Z_F 1     // F = 1.
#define J5P J5N     #define J5P_F 2     // F = 2.
#define J5NN J5N    #define J5NN_F 3    // F = 3.
#define J5NZ J5N    #define J5NZ_F 4    // F = 4.
#define J5NP J5N    #define J5NP_F 5    // F = 5.

#define J6N 46      #define J6N_F 0     // F = 0.
#define J6Z J6N     #define J6Z_F 1     // F = 1.
#define J6P J6N     #define J6P_F 2     // F = 2.
#define J6NN J6N    #define J6NN_F 3    // F = 3.
#define J6NZ J6N    #define J6NZ_F 4    // F = 4.
#define J6NP J6N    #define J6NP_F 5    // F = 5.

// Miscellaneous operators.
#define SLA 6       #define SLA_F 0     // F = 0.
#define SRA SLA     #define SRA_F 1     // F = 1.
#define SLAX SLA    #define SLAX_F 2    // F = 2.
#define SRAX SLA    #define SRAX_F 3    // F = 3.
#define SLC SLA     #define SLC_F 4     // F = 4.
#define SRC SLA     #define SRC_F 5     // F = 5.

#define MOVE 7

#define NOP 0
#define HLT 5       #define HLT_F 2     // F = 2.

// Input/Output operators.
#define IN 36
#define OUT 37
#define IOC 35
#define JRED 38
#define JBUS 34

// Conversion operators.
#define NUM 5       #define NUM_F 0     // F = 0.
#define CHAR NUM    #define CHAR_F 1    // F = 1.

#endif
