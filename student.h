#ifndef STUDENT_H
#define STUDENT_H

#include "constants.h"

// Structure to represent marks for one subject
typedef struct {
    int minor;
    int major;
} SubjectMarks;

// Structure to represent a student
typedef struct {
    char id[MAX_ID_LENGTH];
    char name[MAX_NAME_LENGTH];
    SubjectMarks subjects[NUM_SUBJECTS];
    int totalMarks;
    double percentage;
    char grade[3];
    double cgpa;
    int isPass;
} Student;

// Calculates total marks and percentage for a student
void calculateTotalAndPercentage(Student* student);

// Assigns grade based on percentage and pass/fail status
void assignGrade(Student* student);

// Converts grade to CGPA value
double convertGradeToCGPA(const char* grade);

#endif // STUDENT_H
