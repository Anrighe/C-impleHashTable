#include <stdio.h>
#include "../hash_table.h"


int main()
{

    char * test_string = "Helloo";

    int element = 4;


    //printf("%d\n", hash_function(test_string));

    struct hash_table table = hash_table_init();
    hash_table_insert(table, test_string, &element);

    printf("%d\n", hash_table_get(table, test_string));

    return 0;
}