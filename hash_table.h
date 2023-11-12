#include <stdio.h>
#include <stdlib.h>

#define HASH_TABLE_STD_SIZE 1024

/// @brief Simple hash function that sums the ascii values of the characters in the string and returns the sum as the hash value
/// @param key String used to calculate the hash value
/// @return integer corresponding to the hash value
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

/// @brief Structure that represents a hash table
struct hash_table
{
    void ** table; // void ** is used to store any type of pointer
    int size;
};

/// @brief Inserts an element into the hash table. If the hash value is greater than the size of the table, 
///         the table is resized so that it can fit the newer element. This function does not check if the 
///         element is already in the table
/// @param table Hash table to insert the element into
/// @param key Key used to calculate the hash value
/// @param element Element to insert into the hash table
void hash_table_insert(struct hash_table * table, const char * key, void * element)
{
    int hash = hash_function(key); 
    
    if (table->size <= hash) // the table is too small -> needs resizing
    {
        // copy the old table values to the newer one
        void ** new_table = malloc(sizeof(void*) * (hash + 1));

        for (size_t i = 0; i < hash + 1; ++i)
            new_table[i] = NULL;

        for (size_t i = 0; i < table->size; ++i)
            new_table[i] = table->table[i];

        free(table->table);

        table->table = new_table;
        table->size = hash + 1;
    }

    table->table[hash] = element;
};

/// @brief Gets an element from the hash table and returns it. If the hash value is greater than the table size,
///         the function returns NULL
/// @param table Hash table to get the element from
/// @param key Key used to calculate the hash value
/// @return A pointer to the element in the hash table
void * hash_table_get(struct hash_table * table, const char * key)
{
    int hash = hash_function(key);
    if (table->size <= hash)
        return NULL;

    return table->table[hash];
}

/// @brief Generates a hash table with the standard size `HASH_TABLE_STD_SIZE`. Initializes each element to `NULL and returns it
/// @return A hash table with the standard size `HASH_TABLE_STD_SIZE`
struct hash_table hash_table_init()
{
    struct hash_table table;
    table.table = malloc(sizeof(void *) * HASH_TABLE_STD_SIZE);

    for (size_t i = 0; i < HASH_TABLE_STD_SIZE; ++i)
        table.table[i] = NULL;

    table.size = HASH_TABLE_STD_SIZE;

    return table;
}

