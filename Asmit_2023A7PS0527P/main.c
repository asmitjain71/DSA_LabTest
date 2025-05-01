/*Here’s a complete main.c driver file to test and integrate your components:
1. Reads student data from students.txt
2. Sorts students using insertion sort
3. Writes to sorted_students.txt
4. Inserts into hash table (with open addressing / linear probing)
5. Displays the hash table
*/
// You are free to modify this file as per your wish.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "sorting.h"
#include "hashing.h"

int main() {
    Student *students = NULL;
    int count = 0;

    // Step 1: Read from students.txt
    //students = read_students("students.txt", &count);
    students = read_students(&count);
    if (students == NULL || count == 0) {
        printf("No students loaded.\n");
        return 1;
    }   

    printf("\n--- Students Loaded: %d ---\n", count);
    display_students(students, count);

    // Step 2: Sort by CGPA (descending)
    insertion_sort(students, count);

    printf("\n--- Sorted Students (by CGPA descending) ---\n");
    display_students(students, count);

    // Step 3: Write sorted list to file
    write_students(students, count);


    // Step 4: Initialize and populate hash table
    init_hash_table();
    for (int i = 0; i < count; i++) {
        insert_into_hash_table(students[i]);
    }

    // Step 5: Print full hash table
    print_hash_table();

    // Step 7: Clean up
    free(students);
    free_hash_table();

    return 0;
}


// gcc main.c student.c sorting_branch.c sorting_roll.c hashing.c -o main
// ./main




// // gcc main.c student.c sorting_cgpa.c sorting_branch.c sorting_roll.c hashing.c -o run_all



// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #include "student.h"
// #include "hashing.h"

// // Declare the different insertion sort functions
// void insertion_sort_by_cgpa(Student *students, int count);     // from sorting.c
// void insertion_sort_by_branch(Student *students, int count);   // from sorting_branch.c
// void insertion_sort_by_roll(Student *students, int count);     // from sorting_roll.c

// int main() {
//     Student *students = NULL;
//     int count = 0;

//     // Step 1: Load students from file
//     students = read_students(&count);
//     if (students == NULL || count == 0) {
//         printf("No students loaded.\n");
//         return 1;
//     }

//     printf("\n--- Students Loaded: %d ---\n", count);
//     display_students(students, count);

//     // === Task 1: Sort by CGPA ===
//     insertion_sort_by_cgpa(students, count);
//     printf("\n--- Sorted by CGPA (descending) ---\n");
//     display_students(students, count);
//     write_students("sorted_by_cgpa.txt", students, count);

//     // === Task 2: Sort by BRANCH ===
//     insertion_sort_by_branch(students, count);
//     printf("\n--- Sorted by BRANCH ---\n");
//     display_students(students, count);
//     write_students("sorted_by_branch.txt", students, count);

//     // === Task 2: Sort by ROLL NUMBER ===
//     insertion_sort_by_roll(students, count);
//     printf("\n--- Sorted by ROLL NUMBER ---\n");
//     display_students(students, count);
//     write_students("sorted_by_roll.txt", students, count);

//     // === Task 3: Hash Table ===
//     init_hash_table();
//     for (int i = 0; i < count; i++) {
//         insert_into_hash_table(students[i]);
//     }

//     printf("\n--- Hash Table Contents ---\n");
//     print_hash_table();

//     // Cleanup
//     free(students);
//     free_hash_table();

//     return 0;
// }
