/*
 * week4_2_struct_student.c
 * Author: Mehmet Temiz
 * Student ID: 251ADB232
 * Description:
 *   Defines a Student struct, fills two variables and prints them.
 *   This program reads no input.
 */

#include <stdio.h>
#include <string.h>

/* A student record: name, ID number and grade */
struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  struct Student s1;
  struct Student s2;

  /* Fill the fields with the dot operator */
  strcpy(s1.name, "Alice Johnson");
  s1.id = 1001;
  s1.grade = 9.1f;

  strcpy(s2.name, "Bob Smith");
  s2.id = 1002;
  s2.grade = 8.7f;

  printf("Student 1: %s, ID: %d, Grade: %.1f\n", s1.name, s1.id, s1.grade);
  printf("Student 2: %s, ID: %d, Grade: %.1f\n", s2.name, s2.id, s2.grade);

  return 0;
}