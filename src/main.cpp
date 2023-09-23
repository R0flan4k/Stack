#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "vtor.h"


int main(void)
{
    Stack stk = {};

    AllStackErrors errors = {};

    STACK_CTOR(&stk, &errors);

    STACK_PUSH(&stk, 10.2, &errors);

    SHOW_DUMP(&stk, &errors);

    STACK_PUSH(&stk, 101.7, &errors);

    SHOW_DUMP(&stk, &errors);

    Elem_t value = 0;

    STACK_POP(&stk, &value, &errors);

    SHOW_DUMP(&stk, &errors);

    printf(ELEM_SPEC "\n", value);

    STACK_POP(&stk, &value, &errors);

    SHOW_DUMP(&stk, &errors);

    printf(ELEM_SPEC "\n", value);

    STACK_DTOR(&stk, &errors);

    SHOW_DUMP(&stk, &errors);

    return 0;
}


// TASKS: #ifndef NCANARYPROTECT
//        HASH
//        #ifndef NHASHPROTECT
