//
// Created by Michał Oleniacz on 05/06/2023.
//

#include "stack.h"

/**
 * Initialize empty Stack
 *
 * @return Pointer to Stack
 */
Stack* initStack(int* stackId)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(stack == NULL) handleMallocFailure("Stack:");

    stack->id = *stackId;
    stack->size = 0;
    stack->top = NULL;

    (*stackId)++;

    return stack;
}

/**
 * Push new node onto the stack
 *
 * @param stack
 * @param element
 */
void pushStack(Stack* stack, void *element)
{
    if(stack == NULL) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) handleMallocFailure("pushStack/Node:");

    newNode->data = element;
    newNode->next = stack->top;

    stack->top = newNode;
    stack->size++;
}

/**
 * Remove top node from stack
 *
 * @param stack
 * @return Node
 */
Node* popStack(Stack *stack)
{
    if(stack->size == 0)
        return NULL;

    Node* topNode = stack->top;
    stack->top = stack->top->next;
    stack->size--;
    return topNode;
}

/**
 * Get top node from stack without removing it
 *
 * @param stack
 * @return
 */
Node* peekStack(Stack* stack)
{
    if(stack->size == 0)
        return NULL;

    return stack->top;
}

Node* searchStack(Stack* stack, void* searchStruct, bool (*compareFn)(void*, void*))
{
    if(stack == NULL) {
        printf("Stack not initialized!\n");
        return NULL;
    }

    if(stack->size == 0){
        printf("Empty stack!\n");
        return NULL;
    }

    Node* tmp = stack->top;
    while(tmp != NULL) {
        if(compareFn(tmp->data, searchStruct))
            return tmp;
        tmp = tmp->next;
    }

    return NULL;
};

void serializeStack(Stack *stack, FILE* datafile)
{

}

/**
 * Deallocate stack and nodes stored in it
 *
 * @param stack
 */
void destroyStack(Stack** stack)
{
    if((*stack)->size == 0) {
        free(*stack);
        stack = NULL;
        return;
    }

    while((*stack)->top != NULL) {
        Node* topNode = popStack((*stack));
        destroyNode(&topNode);
    }

    free(*stack);
    (*stack) = NULL;
}


