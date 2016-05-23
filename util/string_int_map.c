#include "string_int_map.h"
#include <stdlib.h>
#include <string.h>

#define STRING_INT_MAP_DEBUG


/*
* Initialize the given hash map to hold the given number of elements.
* Elements will be hashed into the map using the given hashing function.
* map - Pointer to hash map to initialize.
* hashing_function - Function to hash keys into the table.
* initial_capacity - Initial number of elements that can be added to map.
*/
void map_init(string_int_map_pt map,
              hash_function hashing_function,
              unsigned int initial_capacity)
{
#ifdef STRING_INT_MAP_DEBUG
    map->collisions = 0;
#endif
    map->capacity = initial_capacity;
    map->size = 0;
    map->hash_func = hashing_function;
    map->map = calloc(initial_capacity, sizeof(map_elem));
}


/*
* Releases all resources associated with the given hash map.
*/
void map_free(string_int_map_pt map)
{
    for(int i = 0; i < map->capacity; ++i)
    {
        if(map->map[i] != NULL)
        {
            free(map->map[i]->key);
        }
    }
    free(map->map);
}


/*
* Add the given (key, value) pair to the given hash map.
*/
int add(char* key, int value, string_int_map_pt map)
{
    // TODO Need to check that we are not at capacity.

    // Create the hash map element with the given key and value.
    map_elem_pt element = (map_elem_pt)calloc(1, sizeof(map_elem));
    element->key = (char*)calloc(strlen(key) + 1, sizeof(char));
    strcpy(element->key, key);
    element->value = value;

    // Generate hash code for the given key.
    unsigned int hash_code = map->hash_func(key, map->capacity);

    // TODO need to check the bounds of the hash code.

    while(map->map[hash_code] != NULL)
    {
        // Keep looking for an empty spot.
#ifdef STRING_INT_MAP_DEBUG
        map->collisions++;
#endif
        hash_code = (hash_code + 1) % map->capacity;
    }
    map->map[hash_code] = element;
    map->size++;
}


/*
* Generate a hash code for the given string.
*/
unsigned int hash_string(char* key, unsigned int capacity)
{
    unsigned int hash_code = 0;
    for(int i = 0; i < strlen(key); ++i)
    {
        hash_code += (int)key[i];
    }
    return hash_code % capacity;
}


/*
* Get the value for the given key from the given map.
* If the key is not in the map, returns -1.
*/
int get(char* key, string_int_map_pt map)
{
    unsigned int hash_code = map->hash_func(key, map->capacity);
    if(map->map[hash_code] == NULL) return -1;
    while(strcmp(key, map->map[hash_code]->key) != 0)
    {
        hash_code = (hash_code + 1) % map->capacity;
        if(map->map[hash_code] == NULL) return -1;
    }
    return map->map[hash_code]->value;
}


/* Debug functions. */

/*
* Return the number of times a collision occured while adding a new
* element to the given map.
*/
int map_collisions(string_int_map_pt map)
{
#ifdef STRING_INT_MAP_DEBUG
    return map->collisions;
#endif
    return -1;
}

