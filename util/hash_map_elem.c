#include "hash_map_elem.h"
#include <stdlib.h>


/*
* Initializes the given hash map element to an empty element.
* Both the key and value of the element are set to NULL.
*/
void hash_map_elem_init(hash_map_elem_pt element)
{
    element->key = NULL;
    element->value = NULL;
}

/*
* Free up all resources associated with the given hash map element.
* Frees up both the key and value of the hash map.
*/
void hash_map_elem_free(hash_map_elem_pt element)
{
    free(element->key);
    free(element->value);
}

