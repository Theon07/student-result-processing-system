#include "statistics.h"
#include <string.h>

void calculateStatistics(Student students[], int count, Statistics* stats)
{
    int i;
    double totalPercentage = 0.0;
    

    for (i = 0; i < NUM_GRADE_CATEGORIES; i++) {
        stats->gradeCount[i] = 0;
    }
    
    if (count == 0) {
        stats->classAverage = 0.0;
        stats->highestPercentage = 0.0;
        stats->lowestPercentage = 0.0;
        strcpy(stats->topStudentName, "N/A");
        strcpy(stats->lowestStudentName, "N/A");
        return;
    }
    
    stats->highestPercentage = students[0].percentage;
    stats->lowestPercentage = students[0].percentage;
    strcpy(stats->topStudentName, students[0].name);
    strcpy(stats->lowestStudentName, students[0].name);
    
    for (i = 0; i < count; i++) {
        totalPercentage += students[i].percentage;
        
        if (students[i].percentage > stats->highestPercentage) {
            stats->highestPercentage = students[i].percentage;
            strcpy(stats->topStudentName, students[i].name);
        }
        
        if (students[i].percentage < stats->lowestPercentage) {
            stats->lowestPercentage = students[i].percentage;
            strcpy(stats->lowestStudentName, students[i].name);
        }
        
        if (strcmp(students[i].grade, "O") == 0) stats->gradeCount[0]++;
        else if (strcmp(students[i].grade, "A+") == 0) stats->gradeCount[1]++;
        else if (strcmp(students[i].grade, "A") == 0) stats->gradeCount[2]++;
        else if (strcmp(students[i].grade, "B+") == 0) stats->gradeCount[3]++;
        else if (strcmp(students[i].grade, "B") == 0) stats->gradeCount[4]++;
        else if (strcmp(students[i].grade, "C") == 0) stats->gradeCount[5]++;
        else if (strcmp(students[i].grade, "D") == 0) stats->gradeCount[6]++;
        else if (strcmp(students[i].grade, "F") == 0) stats->gradeCount[7]++;
    }
    
    stats->classAverage = totalPercentage / count;
}