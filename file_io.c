#include "file_io.h"
#include "validation.h"
#include <stdlib.h>
#include <string.h>

int readStudentRecord(FILE* file, Student* student, Student students[], int count)
{
    char tempName[MAX_NAME_LENGTH];
    char line[500];
    char* token;
    int i;
    int minor, major;
    
    if (fgets(line, sizeof(line), file) == NULL) {
        return 0; 
    }
    
    
    token = strtok(line, " ");
    if (token == NULL) {
        return -1;
    }
    strcpy(student->id, token);
    
    token = strtok(NULL, "\"");
    if (token == NULL) {
        return -1;
    }
    
    strcpy(tempName, token);
    
    
    
    if (!validateStudentId(student->id, students, count)) {
        fprintf(stderr, "Invalid or duplicate student ID: %s\n", student->id);
        return -1;
    }
    
    
    if (!validateName(tempName)) {
        fprintf(stderr, "Invalid student name: %s\n", tempName);
        return -1;
    }
    
    strcpy(student->name, tempName);
    
    
    for (i = 0; i < NUM_SUBJECTS; i++) {
    
        token = strtok(NULL, " \n");
        if (token == NULL) {
            fprintf(stderr, "Missing minor marks for subject %d (Student: %s)\n", 
                    i + 1, student->id);
            return -1;
        }
        minor = atoi(token);
        
    
        token = strtok(NULL, " \n");
        if (token == NULL) {
            fprintf(stderr, "Missing major marks for subject %d (Student: %s)\n", 
                    i + 1, student->id);
            return -1;
        }
        major = atoi(token);
        
    
        if (!validateMinorMarks(minor)) {
            fprintf(stderr, "Invalid minor marks %d for subject %d (Student: %s)\n", 
                    minor, i + 1, student->id);
            return -1;
        }
        
    
        if (!ValidateMajorMarks(major)) {
            fprintf(stderr, "Invalid major marks %d for subject %d (Student: %s)\n", 
                    major, i + 1, student->id);
            return -1;
        }
        
        student->subjects[i].minor = minor;
        student->subjects[i].major = major;
    }
    
    return 1; 
}

