#include <stdio.h>
#include <string.h>
#include "sorting.h"

// Insertion Sort: The following function sorts students by CGPA in ascending order. You have to modify this function to sort students by BRANCH of BITS_ID.
// Do not use any inbuilt sorting algorithm.



// Sort students by BRANCH (Characters 5-8 of BITS_ID)
void insertion_sort_branch(Student *students, int count) {
    for (int i = 1; i < count; i++) {
        Student key = students[i];
        int j = i - 1;

        // Extract key branch
        char key_branch[5];
        strncpy(key_branch, key.BITS_ID + 4, 4);
        key_branch[4] = '\0';

        while (j >= 0) {
            char current_branch[5];
            strncpy(current_branch, students[j].BITS_ID + 4, 4);
            current_branch[4] = '\0';

            if (strcmp(current_branch, key_branch) > 0) {
                students[j + 1] = students[j];
                j--;
            } else {
                break;
            }
        }

        students[j + 1] = key;
    }
}




