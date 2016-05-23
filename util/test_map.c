#define STRING_INT_MAP_DEBUG
#include "string_int_map.h"

int main()
{
    string_int_map map;
    map_init(&map, hash_string, 15);
    add("ADD", 1, &map);
    add("SUB", 2, &map);
    printf("Collisions: %d\n", map_collisions(&map));
    printf("Value of ADD: %d\n", get("ADD", &map));
    printf("Value of SUB: %d\n", get("SUB", &map));
    map_free(&map);
    return 0;
}
