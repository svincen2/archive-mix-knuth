#include "string_hash_map.h"
#include <stdlib.h>
#include <string.h>


/*
* Releases resources associated with the string hash map element.
*/
void map_elem_free(map_elem_pt element)
{
    printf("Freeing key %p\n", element->key);
    free(element->key);
}


/*
* Initialize the given hash map to hold the given number of elements.
* Elements will be hashed into the map using the given hashing function.
* map - Pointer to hash map to initialize.
* hashing_function - Function to hash keys into the table.
* initial_capacity - Initial number of elements that can be added to map.
*/
void string_hash_map_init(string_hash_map_pt map,
                          string_hash_function hashing_function,
                          unsigned int initial_capacity)
{
#ifdef STRING_HASH_MAP_DEBUG
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
void string_hash_map_free(string_hash_map_pt map)
{
    printf("In hash map free...\n");
    for(int i = 0; i < map->capacity; ++i)
    {
        if(map->map[i] != NULL)
        {
            printf("Freeing element %p\n", map->map[i]);
            map_elem_free(map->map[i]);
        }
    }
    free(map->map);
}


/*
* Add the given (key, value) pair to the given hash map.
*/
int string_hash_map_add(char* key, int value, string_hash_map_pt map)
{
    // TODO Need to check that we are not at capacity.

    // Create the hash map element with the given key and value.
    map_elem_pt element = (map_elem_pt)calloc(1, sizeof(map_elem));
    element->key = (char*)calloc(strlen(key) + 1, sizeof(char));
    printf("Element key %p\n", element->key);
    strcpy(element->key, key);
    element->value = value;

    // Generate hash code for the given key.
    unsigned int hash_code = map->hash_func(key);

    printf("Hash code: %d\n", hash_code);

    // TODO need to check the bounds of the hash code.

    while(map->map[hash_code] != NULL)
    {
        // Keep looking for an empty spot.
#ifdef STRING_HASH_MAP_DEBUG
        map->collisions++;
#endif
        hash_code = (hash_code + 1) % map->capacity;
    }
    printf("Adding to index: %d\n", hash_code);
    printf("Element: %p\n", element);
    map->map[hash_code] = element;
    map->size++;
}


/*
* Generate a hash code for the given string.
*/
unsigned int hash_string(char* key)
{
    unsigned int hash_code = 0;
    printf("key: %s\n", key);
    return 0;
}


/* Debug functions. */

/*
* Return the number of times a collision occured while adding a new
* element to the given map.
*/
int string_hash_map_collisions(string_hash_map_pt map)
{
#ifdef STRING_HASH_MAP_DEBUG
    return map->collisions;
#endif
    return -1;
}

