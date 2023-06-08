//
// Created by Michał Oleniacz on 05/06/2023.
//

#ifndef PROJEKT_STUDENT_H
#define PROJEKT_STUDENT_H

#include "error.h"

#define NO_FIELDS 6

enum Studies {
    IT,
    MATH,
    CHEM,
    PSY,
    SOCIAL,
    OTHER
};

typedef struct {
    char* lastName;
    int birthYear;
    Studies studies;
} Student;

Student* initStudent(const char *lastName, int birthYear, Studies studies);
void freeStudent(Student* student);
void serializeStudent(Student* student, const char* filename);
void printStudent(Student* student);
Student* deserializeStudent(const char* filename);
Studies getStudiesId(const char *value);
char *getStudyFieldName(Studies id);

#endif //PROJEKT_STUDENT_H
