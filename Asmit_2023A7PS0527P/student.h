#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME 50
#define MAX_BITS_ID 14

typedef struct Student {
    char BITS_ID[MAX_BITS_ID];  // 13-character BITS_ID
    char name[MAX_NAME];
    float CGPA;
} Student;

Student* read_students(int *count);
void write_students(Student *students, int count);
//void write_students(const char *filename, Student *students, int count);

void display_students(Student *students, int count);
void free_students(Student *students);

#endif





