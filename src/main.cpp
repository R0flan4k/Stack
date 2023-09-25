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

    STACK_CTOR(&stk, &errors);

    show_stack_menu();

    int choice = 0;
    Elem_t inputed_value = 0;
    Elem_t value = 0;

    while ((choice = get_stack_choice()) != EOF)
    {
        switch (choice)
        {
            case 'p':
                if (fscanf(INPUT_FILE, ELEM_SPEC, &inputed_value) != 1)
                    continue;

                STACK_PUSH(&stk, inputed_value, &errors);

                SHOW_DUMP(&stk, &errors);

                break;

            case 't':
                STACK_POP(&stk, &value, &errors);

                SHOW_DUMP(&stk, &errors);

                printf("Taken value: " ELEM_SPEC "\n", value);

                break;

            default:
                MY_ASSERT(0 && "UNREACHED");
                break;
        }
    }

    STACK_DTOR(&stk, &errors);

    return 0;
}


// TASKS: -DNCANARYPROTECT
