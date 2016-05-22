/*
* Declares a hash map, mapping keys to values.
* Uses a hashing function to determine placement in the map.
* Maps strings to integers.
* Author: Sean Vincent.
*/
#ifndef UTIL_STRING_HASH_MAP_H
#define UTIL_STRING_HASH_MAP_H

#include <stdio.h>


// Initial capacity of a hash map.
static const unsigned int STRING_HASH_MAP_INIT_CAPACITY = 16;

// Alias for a function that produces a hash code.
typedef unsigned int (*string_hash_function)(char*);

/*
* A map element which has a string for a key, and an int for a value.
*/
typedef struct _map_elem
{
    char* key;
    int value;
} map_elem, *map_elem_pt;


/* Functions for working with map elements. */

// Free a map element, releases all resources.
void map_elem_free(map_elem_pt element);


/*
* Hash map which does not hold type information.
* Any type can be put into the table.
*/
typedef struct _string_hash_map
{

#ifdef HASH_MAP_DEBUG
    // Number of times two items hashed to same spot.
    unsigned int collisions;
#endif

    unsigned int capacity;           // Number of available entries in table.
    unsigned int size;               // Number of elements in table.
    string_hash_function hash_func;  // Function used to generate hash codes.
    map_elem_pt* map;                // Variable capacity hash table.
} string_hash_map, *string_hash_map_pt;


/* Functions for using a hash map. */

// Initialize the given hash map.
void string_hash_map_init(string_hash_map_pt map,
                          string_hash_function hashing_function,
                          unsigned int initial_capacity);

// Free the given hash map, releasing all associated resources.
void string_hash_map_free(string_hash_map_pt map);

// Add an element
int string_hash_map_add(char* key, int value, string_hash_map_pt map);

// Hashing function using char* as a key.
unsigned int hash_string(char* key);


/* Debug functions. */

// Returns the number of times a collision occured hashing into the hash map.
int string_hash_map_collisions(string_hash_map_pt map);

#endif

