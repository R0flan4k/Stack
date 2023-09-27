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

    AllStackErrors errors = {};

    if ((errors = stack_ctor(&stk)).error_code)
    {
        show_dump(&stk, &errors);

        return errors.error_code;
    }
    else
    {
        printf("The stack successfully constructed,\n");
    }

    show_stack_menu();

    errors = process_stack(&stk);

    if ((errors = stack_dtor(&stk)).error_code)
    {
        show_dump(&stk, &errors);

        return errors.error_code;
    }
    else
    {
        printf("The stack successfully destructed.\n");
    }

    return 0;
}


// TASKS: -DNCANARYPROTECT
