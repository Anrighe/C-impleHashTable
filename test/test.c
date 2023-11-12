#include <stdio.h>
#include "../hash_table.h"

int main()
{

    char * test_string = "Helloo 123a11a";

    printf("Hash value corresponding to the key '%s' is: %d\n", test_string, hash_function(test_string));

    int element = 4123;

    struct hash_table table = hash_table_init();
    printf("Before hash_table_insert\n");

    hash_table_insert(&table, test_string, &element);

    printf("Before hash_table_get\n");
    printf("The requested element corresponding to the key '%s' is: %d\n", test_string, *(int*)hash_table_get(&table, test_string));

    return 0;
}