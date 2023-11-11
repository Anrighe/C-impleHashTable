#include <stdio.h>
#include <stdlib.h>

#define HASH_TABLE_STD_SIZE 1024

int hash_function(const char * key)
{   
    int hash = 0;
    while (*key != '\0')
    {
        hash += *key;
        key++;
    }

    return hash;
}

//TODO: THIS MIGHT BE ELIMINATED?
struct hash_table_entry
{
    void * element;
};

struct hash_table
{
    struct hash_table_entry * table;
    int size;
};

void hash_table_insert(struct hash_table table, const char * key, void * element)
{
    int hash = hash_function(key);

    // need to check if the current table is less than the hash key number
    // if it is, then we need to resize the table
    // if not, then we can just insert the element into the table
    // but first we need to check if the 
    
    
    if (table.size <= hash) // the table is too small -> needs resizing
    {
        // copy the table
        struct hash_table_entry * new_table = malloc(sizeof(struct hash_table_entry) * (hash + 1));

        for (size_t i = 0; i < table.size; ++i)
            new_table[i] = table.table[i];

        free(table.table);

        table.size = hash + 1;
    }

    table.table[hash].element = element;
};

void * hash_table_get(struct hash_table table, const char * key)
{
    int hash = hash_function(key);

    if (table.size <= hash)
        return NULL;

    return table.table[hash].element;
}

struct hash_table hash_table_init()
{
    struct hash_table table;
    table.table = malloc(sizeof(struct hash_table_entry) * HASH_TABLE_STD_SIZE);
    table.size = HASH_TABLE_STD_SIZE;

    return table;
}

