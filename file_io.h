#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>
#include "student.h"

// Reads and validates one student record from file
// Returns: 1 if successful, 0 if EOF, -1 if invalid data 
int readStudentRecord(FILE* file, Student* student, Student students[], int count);

#endif // FILE_IO_H
