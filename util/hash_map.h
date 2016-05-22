/*
* Declares a hash map, mapping keys to values.
* Uses a hashing function to determine placement in the map.
* Any type can be used as a key.
* Any type can be used as a value.
* Author: Sean Vincent.
*/
#ifndef UTIL_HASH_MAP_H
#define UTIL_HASH_MAP_H

#include "hash_map_elem.h"


// Initial capacity of a hash map.
static const unsigned int HASH_MAP_INIT_CAPACITY = 16;

// Alias for a function that produces a hash code.
typedef unsigned int (*hash_function)(void*);


/*
* Hash map which does not hold type information.
* Any type can be put into the table.
*/
typedef struct _hash_map
{

#ifdef HASH_MAP_DEBUG
    // Number of times two items hashed to same spot.
    unsigned int collisions;
#endif

    unsigned int capacity;    // Number of available entries in table.
    unsigned int size;        // Number of elements in table.
    hash_function hash_func;  // Function used to generate hash codes.
    hash_map_elem_pt* map;    // Variable capacity hash table.
} hash_map, *hash_map_pt;


/* Functions for using a hash map. */

// Initialize the given hash map.
void hash_map_init(hash_map_pt map,
                   hash_function hashing_function,
                   unsigned int initial_capacity);

// Free the given hash map, releasing all associated resources.
void hash_map_free(hash_map_pt map);

// Add an element
int hash_map_add(void* key, void* value, hash_map_pt map);


/* Debug functions. */

// Returns the number of times a collision occured hashing into the hash map.
int hash_map_collisions(hash_map_pt map);

#endif

