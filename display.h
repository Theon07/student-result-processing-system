#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include "student.h"
#include "statistics.h"

// Displays formatted table header
void displayHeader(FILE* output);

// Displays one student's results in tabular format
void displayStudentRecord(FILE* output, Student* student, int index);

// Displays class statistics summary
void displayStatisticsSummary(FILE* output, Statistics* stats, int studentCount);

// Displays grade distribution
void displayGradeDistribution(FILE* output, Statistics* stats);

#endif // DISPLAY_H
