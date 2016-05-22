#include "hash_map.h"
#include <stdlib.h>


/*
* Initialize the given hash map to hold the given number of elements.
* Elements will be hashed into the map using the given hashing function.
* map - Pointer to hash map to initialize.
* hashing_function - Function to hash keys into the table.
* initial_capacity - Initial number of elements that can be added to map.
*/
void hash_map_init(hash_map_pt map,
                   hash_function hashing_function,
                   unsigned int initial_capacity)
{
#ifdef HASH_MAP_DEBUG
    map->collisions = 0;
#endif
    map->capacity = initial_capacity;
    map->size = 0;
    map->hash_func = hashing_function;
    map->map = calloc(initial_capacity, sizeof(hash_map_elem_pt));
}


/*
* Releases all resources associated with the given hash map.
*/
void hash_map_free(hash_map_pt map)
{
    for(int i = 0; i < map->capacity; ++i)
    {
        if(map->map[i] != NULL) free(map->map[i]);
    }
    free(map->map);
}


/*
* Add the given (key, value) pair to the given hash map.
*/
int hash_map_add(void* key, void* value, hash_map_pt map)
{
    // TODO Need to check that we are not at capacity.

    // Create the hash map element with the given key and value.
    hash_map_elem_pt element =
        (hash_map_elem_pt)calloc(1, sizeof(hash_map_elem));
    element->key = key;
    element->value = value;

    // Generate hash code for the given key.
    unsigned int hash_code = map->hash_func(key);

    // TODO need to check the bounds of the hash code.

    while(map->map[hash_code] != NULL)
    {
        // Keep looking for an empty spot.
#ifdef HASH_MAP_DEBUG
        map->collisions++;
#endif
        hash_code = (hash_code + 1) % map->capacity;
    }
    map->map[hash_code] = element;
    map->size++;
}


/* Debug functions. */

/*
* Return the number of times a collision occured while adding a new
* element to the given map.
*/
int hash_map_collisions(hash_map_pt map)
{
#ifdef HASH_MAP_DEBUG
    return map->collisions;
#endif
    return -1;
}

