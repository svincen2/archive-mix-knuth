#ifndef UTIL_HASH_MAP_ELEM_H
#define UTIL_HASH_MAP_ELEM_H

/*
*
*/
typedef struct _hash_map_elem
{
    void* key;
    void* value;
} hash_map_elem, *hash_map_elem_pt;


/* Functions for using hash map elements. */

// Initialize the given hash map element. */
void hash_map_elem_init(hash_map_elem_pt element);

// Free the given hash map element. */
void hash_map_elem_free(hash_map_elem_pt element);

#endif

