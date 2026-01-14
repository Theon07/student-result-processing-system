#ifndef VALIDATION_H
#define VALIDATION_H

#include "student.h"

// Validates student ID - must be alphanumeric and unique
int validateStudentId(const char* id, Student students[], int count);

// Validates name - must contain only alphabets and spaces
int validateName(const char* name);

// Validates minor marks - must be between 0 and 40
int validateMinorMarks(int marks);

// Validates major marks - must be between 0 and 60
int ValidateMajorMarks(int marks);

#endif // VALIDATION_H