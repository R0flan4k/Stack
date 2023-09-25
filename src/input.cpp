#include <stdio.h>
#include <strings.h>

#include "cmd_input.h"
#include "input.h"

int get_stack_choice(void)
{
    int character = 0;

    while ((character = fgetc(INPUT_FILE)) != 'p' && character != 't' && character != EOF)
        continue;

    return character;
}


void show_stack_menu(void)
{
    printf("Enter \"p *number*\" to put your number to stack or\n\
          \renter \"t\" to take a number from stack.\n");
}
