//
// Created by Michał Oleniacz on 05/06/2023.
//

#include "student.h"
#include "utils.h"
#include <cstring>

const char* studyFieldNames[NO_FIELDS] = {
        "IT",
        "MATH",
        "CHEM",
        "PSY",
        "SOCIAL",
        "OTHER"
};

Student* initStudent(const char *lastName, int birthYear, Studies studies)
{
    Student* student = (Student*)malloc(sizeof(Student));
    if(student == NULL) handleMallocFailure("initStudent/Student: ");

    student->birthYear = birthYear;
    student->lastName = strdup(lastName);
    student->studies = studies;

    return student;
}

Studies getStudiesId(const char *value)
{
    if(strcmp(value, studyFieldNames[Studies::IT]) == 0)
        return Studies::IT;
    else if(strcmp(value, studyFieldNames[Studies::MATH]) == 0)
        return Studies::MATH;
    else if(strcmp(value, studyFieldNames[Studies::CHEM]) == 0)
        return Studies::CHEM;
    else if(strcmp(value, studyFieldNames[Studies::PSY]) == 0)
        return Studies::PSY;
    else if(strcmp(value, studyFieldNames[Studies::SOCIAL]) == 0)
        return Studies::SOCIAL;
    else
        return Studies::OTHER;
}

char *getStudyFieldName(Studies id)
{
    if(inRange(id, 0, NO_FIELDS))
        return (char*)(studyFieldNames[id]);
    else handleOutOfRange("getStudyFieldName/id: ");
}

bool searchByName(void* data, void* searchResult)
{
    Student* studentData = (Student*)data;
    Student* search = (Student*)searchResult;

    if(strcmp(studentData->lastName, search->lastName) == 0)
        return true;
    return false;
}

bool searchByStudy(void* data, void* searchResult)
{
    Student* studentData = (Student*)data;
    Student* search = (Student*)searchResult;

    if(studentData->studies == search->studies)
        return true;
    return false;
}

bool searchByYear(void* data, void* searchResult)
{
    Student* studentData = (Student*)data;
    Student* search = (Student*)searchResult;

    if(studentData->birthYear == search->birthYear)
        return true;
    return false;
}

void printStudent(Student* student)
{
    printf("\nStudent: %s\nField of study: %s,\nBirth year: %d\n\n",
           student->lastName,
           getStudyFieldName(student->studies),
           student->birthYear
    );
}