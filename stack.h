//
// Created by Michał Oleniacz on 05/06/2023.
//

#ifndef PROJEKT_STACK_H
#define PROJEKT_STACK_H

#include "node.h"
#include "stdlib.h"
#include "error.h"

typedef struct Stack {
    Node* top;
    size_t size;
    int id;
} Stack;

Stack* initStack(int* stackId);
void pushStack(Stack* stack, void *element);
Node* popStack(Stack* stack);
Node* peekStack(Stack* stack);
void serializeStack(Stack* stack, FILE* datafile);
void deserializeStack(Stack* stack, FILE* datafile);
void printStack(Stack* stack);
Node* searchStack(Stack* stack, void* searchStruct, bool (*compareFn)(void*, void*));
void destroyStack(Stack** stack);

#endif //PROJEKT_STACK_H
