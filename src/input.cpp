#include <stdio.h>
#include <strings.h>

#include "cmd_input.h"
#include "input.h"
#include "stack.h"
#include "vtor.h"
#include "my_assert.h"

static int get_stack_choice(void);


void show_stack_menu(void)
{
    printf("Enter \"p *number*\" to put your number to stack,\n\
          \renter \"t\" to take a number from stack or\n\
          \renter \"s\" to show the stack.\n");
}


AllStackErrors process_stack(Stack * stk)
{
    AllStackErrors errors = {};
    int choice = 0;
    Elem_t inputed_value;
    Elem_t value = 0;

    while ((choice = get_stack_choice()) != EOF)
    {
        switch (choice)
        {
            case 'p':
                if (fscanf(INPUT_FILE, ELEM_SPEC, &inputed_value) != 1)
                    continue;

                if ((errors = stack_push(stk, inputed_value)).error_code)
                {
                    show_dump(stk, &errors);

                    return errors;
                }

                printf("Entered value: " ELEM_SPEC "\n", inputed_value);

                break;

            case 't':
                if ((errors = stack_pop(stk, &value)).error_code)
                {
                    show_dump(stk, &errors);

                    return errors;
                }

                printf("Taken value: " ELEM_SPEC "\n", value);

                break;

            case 's':
                show_dump(stk, &errors);

                break;

            default:
                MY_ASSERT(0 && "UNREACHED");

                break;
        }
    }

    return errors;
}


static int get_stack_choice(void)
{
    int character = 0;

    while ((character = fgetc(INPUT_FILE)) != 'p' && character != 't' && character != 's' && character != EOF)
        continue;

    return character;
}
