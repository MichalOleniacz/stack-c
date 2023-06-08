//
// Created by Michał Oleniacz on 08/06/2023.
//

#include "interface.h"
#include "stack.h"
#include "student.h"
#include "stdio.h"
#include <string.h>

void addToStack(Stack* stack)
{
    char lastname[512], studies[512];
    int year;

    scanf("%s", lastname);
    scanf("%s", studies);
    scanf("%d", &year);

    char *lastnamePtr = (char *)malloc((strlen(lastname) + 1) * sizeof(char));
    if(lastnamePtr == NULL) handleMallocFailure("addToStack/Surname");
    strcpy(lastnamePtr, lastname);

    Studies studiesId = getStudiesId(studies);

    Student* newStudent = initStudent(lastname, year, studiesId);

    pushStack(stack, (void**)newStudent);

    return;
}

Student *popFromStack(Stack* stack)
{
    Node* topNode = popStack(stack);
    Student* student = (Student*)topNode->data;
    return student;
}

Student *peekAtStack(Stack* stack)
{
    Node* topNode = peekStack(stack);
    Student* student = (Student*)topNode->data;
    return student;
}

void printFullStack(Stack* stack)
{
    if(stack == NULL)
        return;

    if(stack->size == 0) {
        printf("Empty Stack.\n");
        return;
    }

    printf("Printing Stack (#%d)\n", stack->id);

    Node* tmp = stack->top;
    printf("%s\n", ((Student*)stack->top->data)->lastName);
    while(tmp != NULL) {
        printStudent((Student*)tmp->data);
        tmp = tmp->next;
    }
}

void printTopNode(Stack* stack)
{
    Student* student = peekAtStack(stack);
    printStudent(student);
}

void removeStack(Stack** stack)
{
    return;
}
void saveStack(Stack* stack)
{
    return;
}
Stack* readStack(Stack* stack)
{
    return NULL;
}
