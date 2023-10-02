#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmd_input.h"
#include "my_assert.h"
#include "stack.h"

static void set_flag_stack_push(void);

Elem_t PUSH_NUMBER = 10.2;

FILE * INPUT_FILE = stdin;
FILE * OUTPUT_ERROR_FILE = stderr;
static char * * cmd_input = NULL;

CmdLineArg STACK_PUSH = {
    .name =          "--push",
    .num_of_param =  1,
    .flag_function = set_flag_stack_push,
    .argc_number =   0,
    .help =          "--push *double number*"
};


bool check_cmd_input(int argc, char * * argv)
{
    MY_ASSERT(argv != nullptr);

    cmd_input = argv;

    const char * program_name = argv[0];

    CmdLineArg * flags[] = {&STACK_PUSH};
    size_t flags_array_size = sizeof(flags) / sizeof(flags[0]);

    for (size_t i = 0; i  < flags_array_size; i++)
    {
        for (int j = 1; j < argc; j++)
        {
            if (strcmp(flags[i]->name, argv[j]) == 0)
            {
                if (argc > j + flags[i]->num_of_param)
                {
                    flags[i]->argc_number = j;

                    flags[i]->flag_function();
                }
                else
                {
                    printf("Error. Please, use %s %s\n", program_name, flags[i]->help);
                    return false;
                }
            }
        }
    }

    return true;
}


static void set_flag_stack_push(void)
{
    PUSH_NUMBER = atof(cmd_input[STACK_PUSH.argc_number + 1]);
}
