#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashing.h"

Student hash_table[HASH_TABLE_SIZE];       // Hash table array
int occupied[HASH_TABLE_SIZE] = {0};       // Slot usage flags (0 = empty, 1 = filled)

// Hash function: Sum of ASCII values mod HASH_TABLE_SIZE
int hash_function(char BITS_ID[]) {
  // Implement this function here.
    int sum = 0;
    for (int i = 0; i < 13; i++) {
        sum += (int)BITS_ID[i];
    }
    return sum % HASH_TABLE_SIZE;
}

// Initialize hash table
void init_hash_table() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        occupied[i] = 0;
    }
}

// Insert student using linear probing
void insert_into_hash_table(Student student) {
  // Implement this function here.
    int index = hash_function(student.BITS_ID);

    // Linear probing
    int original_index = index;
    while (occupied[index]) {
        index = (index + 1) % HASH_TABLE_SIZE;

        // Optional safety check to avoid infinite loop if table is full
        if (index == original_index) {
            printf("Error: Hash table is full, cannot insert %s\n", student.BITS_ID);
            return;
        }
    }

    hash_table[index] = student;
    occupied[index] = 1;
}




//Function to print the Hash Table.
void print_hash_table() {
    printf("\n--- Hash Table ---\n");
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        printf("Index %2d: ", i);
        if (occupied[i]) {
            printf("%s, %s, %.2f\n", hash_table[i].BITS_ID, hash_table[i].name, hash_table[i].CGPA);
        } else {
            printf("Empty\n");
        }
    }
}

void free_hash_table()
{
}

// init_hash_table();  // Initialize before inserting

// for (int i = 0; i < count; i++) {
//     insert_into_hash_table(students[i]);
// }

// print_hash_table();  // To view the table
//     