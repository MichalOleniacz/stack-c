#include <iostream>
#include "stack.h"
#include "menu.h"

int main()
{
    int STACK_ID = 1;
    Stack* stack = initStack(&STACK_ID);

    startWithMenu(stack);
    return 0;
}
