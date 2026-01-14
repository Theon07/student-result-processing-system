#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "file_io.h"
#include "statistics.h"
#include "display.h"

int main(int argc, char* argv[])
{
    FILE* inputFile;
    Student students[MAX_STUDENTS];
    Statistics stats;
    int studentCount = 0;
    int readResult;
    int i;
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    
    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error: Cannot open file '%s'\n", argv[1]);
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    
    while (studentCount < MAX_STUDENTS) {
        readResult = readStudentRecord(inputFile, &students[studentCount], 
            students, studentCount);
        
            if (readResult == 0) {
            break; 
        } else if (readResult == -1) {
            continue; 
        }
        
        calculateTotalAndPercentage(&students[studentCount]);
        assignGrade(&students[studentCount]);
        
        studentCount++;
    }
    
    fclose(inputFile);
    
    
    calculateStatistics(students, studentCount, &stats);
    
    
    displayHeader(stdout);
    for (i = 0; i < studentCount; i++) {
        displayStudentRecord(stdout, &students[i], i);
    }
    
    displayStatisticsSummary(stdout, &stats, studentCount);
    displayGradeDistribution(stdout, &stats);
    
    return EXIT_SUCCESS;
}