#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "vtor.h"


StackErrors stack_vtor(const Stack * stk)
{
    StackErrors verificator =         {};

    if (stk->size < 0)
    {
        verificator.invalid_size =         true;

        verificator.error_code |= INVALID_SIZE;
    }

    if (stk->capacity < 0)
    {
        verificator.invalid_capacity =     true;

        verificator.error_code |= INVALID_CAPACITY;
    }

    if (stk->size >= stk->capacity)
    {
        verificator.invalid_sizecapacity = true;

        verificator.error_code |= INVALID_SIZECAPACITY;
    }

    if (stk->data == nullptr)
    {
        verificator.invalid_data =         true;

        verificator.error_code |= INVALID_DATA;
    }

    return verificator;
}


void show_dump(const Stack * stk, const char * stack_name, const StackErrors * verificator, const char * func, const int line, const char * file)
{
    printf("Stack[%p] \"%s\" from %s(%d), %s\n", stk, stack_name, file, line, func);
    printf("{\n");
    printf("    size =     %d\n", stk->size);
    printf("    capacity = %d\n", stk->capacity);
    printf("    data[%p]\n", stk->data);
    printf("    {\n");

    int i = 0;

    while (i < stk->size)
    {
        printf("        [%d] = " ELEM_SPEC, i, stk->data[i]);
    }

    printf("    }\n");
    printf("}\n");
    printf("Errors:\n");

    if (verificator->invalid_size)
        printf(RED_COLOR "invlid size\n" DEFAULT_COLOR);

    if (verificator->invalid_capacity)
        printf(RED_COLOR "invalid capacity\n" DEFAULT_COLOR);

    if (verificator->invalid_sizecapacity)
        printf(RED_COLOR "capacity less than size\n" DEFAULT_COLOR);

    if (verificator->invalid_data)
        printf(RED_COLOR "data is nullptr\n" DEFAULT_COLOR);
}
