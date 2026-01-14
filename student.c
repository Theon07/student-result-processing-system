#include "student.h"
#include <string.h>

void calculateTotalAndPercentage(Student* student)
{
    int i;
    int total = 0;
    int maxMarks = NUM_SUBJECTS * SUBJECT_MAX_MARKS;
    
    student->isPass = 1;
    
    for (i = 0; i < NUM_SUBJECTS; i++) {
        int subjectTotal = student->subjects[i].minor + student->subjects[i].major;
        total += subjectTotal;
        
        if ((subjectTotal * 100.0 / SUBJECT_MAX_MARKS) < PASSING_PERCENTAGE) {
            student->isPass = 0;
        }
    }
    
    student->totalMarks = total;
    student->percentage = (total * 100.0) / maxMarks;
}

void assignGrade(Student* student)
{
    if (!student->isPass) {
        strcpy(student->grade, "F");
        student->cgpa = CGPA_F;
        return;
    }
    
    if (student->percentage >= GRADE_O_MIN) {
        strcpy(student->grade, "O");
    } else if (student->percentage >= GRADE_A_PLUS_MIN) {
        strcpy(student->grade, "A+");
    } else if (student->percentage >= GRADE_A_MIN) {
        strcpy(student->grade, "A");
    } else if (student->percentage >= GRADE_B_PLUS_MIN) {
        strcpy(student->grade, "B+");
    } else if (student->percentage >= GRADE_B_MIN) {
        strcpy(student->grade, "B");
    } else if (student->percentage >= GRADE_C_MIN) {
        strcpy(student->grade, "C");
    } else if (student->percentage >= GRADE_D_MIN) {
        strcpy(student->grade, "D");
    } else {
        strcpy(student->grade, "F");
    }
    
    student->cgpa = convertGradeToCGPA(student->grade);
}

double convertGradeToCGPA(const char* grade)
{
    if (strcmp(grade, "O") == 0) return CGPA_O;
    if (strcmp(grade, "A+") == 0) return CGPA_A_PLUS;
    if (strcmp(grade, "A") == 0) return CGPA_A;
    if (strcmp(grade, "B+") == 0) return CGPA_B_PLUS;
    if (strcmp(grade, "B") == 0) return CGPA_B;
    if (strcmp(grade, "C") == 0) return CGPA_C;
    if (strcmp(grade, "D") == 0) return CGPA_D;
    return CGPA_F;
}

