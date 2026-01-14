#include "validation.h"
#include <string.h>
#include <ctype.h>

#include <stdio.h>

int validateStudentId(const char* id, Student students[], int count)
{
    int i;
    
    if (strlen(id) == 0) {
        return 0;
    }
    
    for (i = 0; id[i] != '\0'; i++) {
        if (!isalnum(id[i])) {
            return 0;
        }
    }
    
    for (i = 0; i < count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            return 0;
        }
    }
    
    return 1;
}

int validateName(const char* name)
{

    // printf("%s:%d ==> %s\n", __FILE__, __LINE__, name);
    int i;
    
    if (strlen(name) == 0) {
        return 0;
    }
    
    for (i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            return 0;
        }
    }
    
    return 1;
}

int validateMinorMarks(int marks)
{
    return (marks >= 0 && marks <= MINOR_MAX_MARKS);
}

int ValidateMajorMarks(int marks)
{
    return (marks >= 0 && marks <= MAJOR_MAX_MARKS);
}

