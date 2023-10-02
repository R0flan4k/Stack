#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "vtor.h"
#include "cmd_input.h"
#include "input.h"
#include "my_assert.h"


int main(int argc, char * argv[])
{
    if (!check_cmd_input(argc, argv))
        return 1;

    Stack stk = {};

    Error_t errors = 0;

    if ((errors = stack_ctor(&stk)))
    {
        show_dump(&stk, &errors);

        return errors;
    }
    else
    {
        printf("The stack successfully constructed,\n");
    }

    show_stack_menu();

    errors = process_stack(&stk);

    if ((errors = stack_dtor(&stk)))
    {
        show_dump(&stk, &errors);

        return errors;
    }
    else
    {
        printf("The stack successfully destructed.\n");
    }

    return 0;
}


// TASKS: -DNCANARYPROTECT
