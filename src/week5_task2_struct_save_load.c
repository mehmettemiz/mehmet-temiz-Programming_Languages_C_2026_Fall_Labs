// week5_task2_struct_save_load.c
// Name: Mehmet  Surname: Temiz  Student ID: 251ADB232
//
// Task 2: Save and load structured records from a file
// Week 5 – Files & Modular Programming
//
// Build: make lab5   Run: ./bin/week5_task2_struct_save_load

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct Student {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

// Function prototypes (do not change these signatures – the autograder calls them directly)
int save_student(const Student *s, const char *filename);  // 0 on success, -1 on error
int load_student(const char *filename, Student *out);      // 0 on success, -1 on error

int main(void) {
    Student s1 = {0};
    strcpy(s1.name, "Alice");
    s1.age = 21;
    s1.gpa = 3.75f;

    Student loaded = {0};
    const char *filename = "student.txt";

    printf("Saving student to file...\n");
    if (save_student(&s1, filename) != 0) {
        fprintf(stderr, "Error: could not save student.\n");
        return EXIT_FAILURE;
    }

    printf("Loading student from file...\n");
    if (load_student(filename, &loaded) != 0) {
        fprintf(stderr, "Error: could not load student.\n");
        return EXIT_FAILURE;
    }

    printf("Loaded student: %s, %d, GPA %.2f\n", loaded.name, loaded.age, loaded.gpa);

    return EXIT_SUCCESS;
}

// Saves one record as "name age gpa" on a single line.
int save_student(const Student *s, const char *filename) {
    if (s == NULL || filename == NULL) {
        return -1;
    }

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return -1;
    }

    int written = fprintf(fp, "%s %d %.2f\n", s->name, s->age, s->gpa);

    if (fclose(fp) != 0 || written < 0) {
        return -1;
    }
    return 0;
}

// Loads one record; returns -1 if the file can't be opened or read.
int load_student(const char *filename, Student *out) {
    if (filename == NULL || out == NULL) {
        return -1;
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    Student tmp = {0};
    int fields = fscanf(fp, "%49s %d %f", tmp.name, &tmp.age, &tmp.gpa);
    fclose(fp);   // close the file in every case

    if (fields != 3) {
        return -1;
    }

    *out = tmp;
    return 0;
}