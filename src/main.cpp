#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "vtor.h"
#include "cmd_input.h"


int main(int argc, char * argv[])
{
    if (!check_cmd_input(argc, argv))
        return 1;

    Stack stk = {};

    AllStackErrors errors = {};

    STACK_CTOR(&stk, &errors);

    STACK_PUSH(&stk, PUSH_NUMBER, &errors);

    SHOW_DUMP(&stk, &errors);

    Elem_t value = 0;

    STACK_POP(&stk, &value, &errors);

    SHOW_DUMP(&stk, &errors);

    printf(ELEM_SPEC "\n", value);

    STACK_DTOR(&stk, &errors);

    errors = stack_vtor(&stk);

    SHOW_DUMP(&stk, &errors);

    return 0;
}


// TASKS: -DNCANARYPROTECT
