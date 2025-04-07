#ifndef HASHING_H
#define HASHING_H

#include "student.h"

#define HASH_TABLE_SIZE 100  // Hash table size

typedef struct Node {
    Student data;
    struct Node *next;
} Node;

void init_hash_table();
void insert_into_hash_table(Student student);
void print_hash_table();
void free_hash_table();
#endif
