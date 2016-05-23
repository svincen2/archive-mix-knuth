/*
* Declares a hash map, mapping keys to values.
* Uses a hashing function to determine placement in the map.
* Maps strings to integers.
* Author: Sean Vincent.
*/
#ifndef UTIL_STRING_INT_MAP_H
#define UTIL_STRING_INT_MAP_H

#include <stdio.h>

#define STRING_INT_MAP_DEBUG


// Alias for hashing a string.
typedef unsigned int (*hash_function)(char*, unsigned int);


/*
* A map element which has a string for a key, and an int for a value.
*/
typedef struct _map_elem
{
    char* key;
    int value;
} map_elem, *map_elem_pt;


/*
* Hash map which does not hold type information.
* Any type can be put into the table.
*/
typedef struct _string_int_map
{

#ifdef STRING_INT_MAP_DEBUG
    // Number of times two items hashed to same spot.
    unsigned int collisions;
#endif

    unsigned int capacity;      // Number of available entries in table.
    unsigned int size;          // Number of elements in table.
    hash_function hash_func;    // Function used to generate hash codes.
    map_elem_pt* map;           // Variable capacity hash table.
} string_int_map, *string_int_map_pt;


/* Functions for using a hash map. */

// Initialize the given hash map.
void map_init(string_int_map_pt map,
              hash_function hashing_function,
              unsigned int initial_capacity);

// Free the given hash map, releasing all associated resources.
void map_free(string_int_map_pt map);

// Add an element
int add(char* key, int value, string_int_map_pt map);

// Hashing function using char* as a key.
unsigned int hash_string(char* key, unsigned int capacity);

// Get the value associated with the given key.
int get(char* key, string_int_map_pt map);


/* Debug functions. */

// Returns the number of times a collision occured hashing into the hash map.
int map_collisions(string_int_map_pt map);

#endif

