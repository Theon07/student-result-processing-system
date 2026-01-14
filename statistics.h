#ifndef STATISTICS_H
#define STATISTICS_H

#include "student.h"

// Structure to hold class statistics
typedef struct {
    double classAverage;
    double highestPercentage;
    double lowestPercentage;
    char topStudentName[MAX_NAME_LENGTH];
    char lowestStudentName[MAX_NAME_LENGTH];
    int gradeCount[NUM_GRADE_CATEGORIES]; // O, A+, A, B+, B, C, D, F 
} Statistics;

// Calculates all statistics for the class
void calculateStatistics(Student students[], int count, Statistics* stats);

#endif // STATISTICS_H
