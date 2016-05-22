#define STRING_HASH_MAP_DEBUG
#include "string_hash_map.h"

int main()
{
    string_hash_map map;
    string_hash_map_init(&map, hash_string, 5);
    string_hash_map_add("hello", 1, &map);
    string_hash_map_add("hello", 2, &map);
    string_hash_map_free(&map);
    printf("Collisions: %d\n", string_hash_map_collisions(&map));
    return 0;
}
