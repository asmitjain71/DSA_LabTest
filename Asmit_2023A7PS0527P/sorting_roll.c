#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sorting.h"

// Insertion Sort: The following function sorts students by CGPA in ascending order. You have to modify this function to sort students by ROLL NUMBER of BITS_ID.
// Do not use any inbuilt sorting algorithm.


// Sort students by ROLL NUMBER (Characters 9-12 of BITS_ID)
void insertion_sort(Student *students, int count) {
    for (int i = 1; i < count; i++) {
        Student key = students[i];
        int j = i - 1;

        // Extract key roll number as integer
        char roll_str[5];
        strncpy(roll_str, key.BITS_ID + 8, 4);
        roll_str[4] = '\0';
        int key_roll = atoi(roll_str);

        while (j >= 0) {
            char current_roll_str[5];
            strncpy(current_roll_str, students[j].BITS_ID + 8, 4);
            current_roll_str[4] = '\0';
            int current_roll = atoi(current_roll_str);

            if (current_roll > key_roll) {
                students[j + 1] = students[j];
                j--;
            } else {
                break;
            }
        }

        students[j + 1] = key;
    }
}
