#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

// Function to read students dynamically from "students.txt". Start from dynamically allocating memory for 50 Student records. Increase the memory in steps of 30 for more student records.

// Student* read_students(int *count) {
//   //Implement this function here.
//     FILE *file = fopen("students.txt", "r");
//     if (!file) {
//         perror("Error opening students.txt");
//         *count = 0;
//         return NULL;
//     }

//     int capacity = 50;  // Initial capacity
//     *count = 0;

//     Student *students = (Student*) malloc(capacity * sizeof(Student));
//     if (!students) {
//         perror("Memory allocation failed");
//         fclose(file);
//         return NULL;
//     }

//     while (1) {
//         Student s;
//         int read = fscanf(file, "%13s %49s %f", s.BITS_ID, s.name, &s.CGPA);
//         if (read != 3) break;

//         if (*count >= capacity) {
//             capacity += 30;
//             Student *temp = (Student*) realloc(students, capacity * sizeof(Student));
//             if (!temp) {
//                 perror("Memory reallocation failed");
//                 free(students);
//                 fclose(file);
//                 return NULL;
//             }
//             students = temp;
//         }

//         students[*count] = s;
//         (*count)++;
//     }

//     fclose(file);
//     return students;
// }


// // Function to write sorted students to "sorted_students.txt"
// void write_students(Student *students, int count) {
//   //You can use this function, if needed.
//     FILE *file = fopen("sorted_students.txt", "w");
//     if (!file) {
//         perror("Error opening sorted_students.txt");
//         exit(1);
//     }

//     for (int i = 0; i < count; i++) {
//         fprintf(file, "%s %s %.2f\n", students[i].BITS_ID, students[i].name, students[i].CGPA);
//     }
//     fclose(file);

// }

// // Function to display students
// void display_students(Student *students, int count) {
//     for (int i = 0; i < count; i++) {
//         printf("%s %s %.2f\n", students[i].BITS_ID, students[i].name, students[i].CGPA);
//     }
// }

// // Function to free dynamically allocated memory
// void free_students(Student *students) {
//     free(students);
// }


Student* read_students(int *count) {
    FILE *file = fopen("students.txt", "r");
    if (!file) {
        perror("Error opening students.txt");
        *count = 0;
        return NULL;
    }

    int capacity = 50;
    *count = 0;

    Student *students = (Student*) malloc(capacity * sizeof(Student));
    if (!students) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    while (1) {
        Student s;
        int read = fscanf(file, "%13s %49s %f", s.BITS_ID, s.name, &s.CGPA);
        if (read != 3) break;

        s.BITS_ID[13] = '\0';
        s.name[MAX_NAME - 1] = '\0';

        if (*count >= capacity) {
            capacity += 30;
            Student *temp = (Student*) realloc(students, capacity * sizeof(Student));
            if (!temp) {
                perror("Memory reallocation failed");
                free(students);
                fclose(file);
                return NULL;
            }
            students = temp;
        }

        students[*count] = s;
        (*count)++;
    }

    fclose(file);
    return students;
}


// Function to write sorted students to "sorted_students.txt"
void write_students(Student *students, int count) {
  //You can use this function, if needed.
    FILE *file = fopen("sorted_students.txt", "w");
    if (!file) {
        perror("Error opening sorted_students.txt");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %.2f\n", students[i].BITS_ID, students[i].name, students[i].CGPA);
    }
    fclose(file);

}

// Function to display students
void display_students(Student *students, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s %s %.2f\n", students[i].BITS_ID, students[i].name, students[i].CGPA);
    }
}

// Function to free dynamically allocated memory
void free_students(Student *students) {
    free(students);
}





// #include <stdio.h>
// #include "student.h"

// int main() {
//     int count;
//     Student *students = read_students(&count);

//     printf("Total students read: %d\n", count);
//     display_students(students, count);

//     // Optional: write to sorted_students.txt
//     write_students(students, count);

//     free_students(students);
//     return 0;
// }




