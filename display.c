#include "display.h"
#include <stdio.h>
#include <string.h>

void displayHeader(FILE *output)
{
    fprintf(output, "\n");
    fprintf(output, "==================================================================================================================================\n");
    fprintf(output, "                              STUDENT RESULT PROCESSING SYSTEM                                     \n");
    fprintf(output, "==================================================================================================================================\n");
    fprintf(output, "%-4s %-10s %-25s %-40s %-6s %-10s %-6s %-6s\n",
            "No.", "ID", "Name", "Marks (Mi-Ma | Mi-Ma | Mi-Ma | Mi-Ma | Mi-Ma)",
            "\tTotal", "Percentage", "Grade", "CGPA");
    fprintf(output, "---------------------------------------------------------------------------------------------------------------------------------\n");
}

void displayStudentRecord(FILE *output, Student *student, int index)
{
    int i;
    char marksStr[100];
    char tempStr[20];

    strcpy(marksStr, "\t");
    for (i = 0; i < NUM_SUBJECTS - 1; i++)
    {
        sprintf(tempStr, " %2d %2d |", student->subjects[i].minor, student->subjects[i].major);
        strcat(marksStr, tempStr);
    }
    sprintf(tempStr, " %2d %2d", student->subjects[NUM_SUBJECTS - 1].minor, student->subjects[NUM_SUBJECTS - 1].major);
    strcat(marksStr, tempStr);

    fprintf(output, "%-4d %-10s %-25s %-50s %-6d %-10.2f %-6s %-6.2f\n",
            index + 1,
            student->id,
            student->name,
            marksStr,
            student->totalMarks,
            student->percentage,
            student->grade,
            student->cgpa);
}

void displayStatisticsSummary(FILE *output, Statistics *stats, int studentCount)
{
    fprintf(output, "==================================================================================================================================\n");
    fprintf(output, "\n");
    fprintf(output, "CLASS STATISTICS:\n");
    fprintf(output, "-----------------\n");
    fprintf(output, "Total Students: %d\n", studentCount);
    fprintf(output, "Class Average Percentage: %.2f%%\n", stats->classAverage);
    fprintf(output, "Highest Percentage: %.2f%% (%s)\n",
            stats->highestPercentage, stats->topStudentName);
    fprintf(output, "Lowest Percentage: %.2f%% (%s)\n",
            stats->lowestPercentage, stats->lowestStudentName);
    fprintf(output, "\n");
}

void displayGradeDistribution(FILE *output, Statistics *stats)
{
    fprintf(output, "GRADE DISTRIBUTION:\n");
    fprintf(output, "-------------------\n");
    fprintf(output, "Grade O  : %d student(s)\n", stats->gradeCount[0]);
    fprintf(output, "Grade A+ : %d student(s)\n", stats->gradeCount[1]);
    fprintf(output, "Grade A  : %d student(s)\n", stats->gradeCount[2]);
    fprintf(output, "Grade B+ : %d student(s)\n", stats->gradeCount[3]);
    fprintf(output, "Grade B  : %d student(s)\n", stats->gradeCount[4]);
    fprintf(output, "Grade C  : %d student(s)\n", stats->gradeCount[5]);
    fprintf(output, "Grade D  : %d student(s)\n", stats->gradeCount[6]);
    fprintf(output, "Grade F  : %d student(s)\n", stats->gradeCount[7]);
    fprintf(output, "\n");
}
