//
// Created by Michał Oleniacz on 05/06/2023.
//

#include "menu.h"
#include "interface.h"

#define OPTIONS_COUNT 8

static const char* options[] = {
        "Stack options:",
        "1 \t Print stack",
        "2 \t Push to stack",
        "3 \t Pop from stack",
        "4 \t Peak at stack",
        "5 \t Serialize stack",
        "6 \t Deserialize stack",
        "7 \t Exit",
};

int getSelection()
{
    int selection;
    scanf("%d", &selection);
    return selection;
}

void printMenu()
{
    for (int i = 0; i < OPTIONS_COUNT; i++)
        printf("%s\n", options[i]);
}

short handleSelection(Stack* stack)
{
    // TODO: Figure out selection and control flow
    int selection = getSelection();

    switch (selection) {
        case 1:
            printFullStack(stack);
            break;
        case 2:
            addToStack(stack);
            break;
        case 3:
            popFromStack(stack);
            break;
        case 4:
            printTopNode(stack);
            break;
        case 5:
            saveStack(stack);
            break;
        case 6:
            readStack(stack);
            break;
        case 7:
            return -1;
        default:
            return 0;
    }

    return 0;
}

void startWithMenu(Stack* stack)
{
    while(true) {
        printMenu();
        if(handleSelection(stack) == -1)
            break;
    }



}



