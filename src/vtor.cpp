#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "vtor.h"


const char * OUTPUT_ERRORS[] = {
    "invlid size\n",
    "invalid capacity\n",
    "capacity less than size\n",
    "data is nullptr\n",
    "can't allocate a memory\n",
    "can't destruct destructed\n",
    "can't constrict the stack capacity\n",
    "can't pop an empty stack\n",
    "spoiled left canary\n",
    "spoiled right canary\n"
};

StackErrors stack_vtor(const Stack * stk)
{
    StackErrors verificator = {};

    if (stk->size < 0)
    {
        verificator.invalid_size =            true;

        verificator.error_code |= STACKERRORS_INVALID_SIZE;
    }

    if (stk->capacity < 0)
    {
        verificator.invalid_capacity =        true;

        verificator.error_code |= STACKERRORS_INVALID_CAPACITY;
    }

    if (stk->size >= stk->capacity)
    {
        verificator.invalid_sizecapacity =    true;

        verificator.error_code |= STACKERRORS_INVALID_SIZECAPACITY;
    }

    if (stk->data == nullptr)
    {
        verificator.invalid_data =            true;

        verificator.error_code |= STACKERRORS_INVALID_DATA;
    }

    if (stk->left_jagajaga != JAGAJAGA_VALUE)
    {
        verificator.spoiled_left_jagajaga =   true;

        verificator.error_code |= STACKERRORS_SPOILED_LEFT_JAGAJAGA;
    }

    if (stk->right_jagajaga != JAGAJAGA_VALUE)
    {
        verificator.spoiled_right_jagajaga =   true;

        verificator.error_code |= STACKERRORS_SPOILED_RIGHT_JAGAJAGA;
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

    int i = 1;

    while (i <= stk->size && stk->data != nullptr)
    {
        printf("        [%d] = " ELEM_SPEC "\n", i, stk->data[i]);

        i++;
    }

    printf("    }\n");
    printf("}\n");

    if (verificator->error_code)
    {
    bool errors[] = {verificator->invalid_size,          verificator->invalid_capacity,
                     verificator->invalid_sizecapacity,  verificator->invalid_data,
                     verificator->cant_allocate_memory,  verificator->cant_destruct,
                     verificator->cant_constrict,        verificator->empty_stack,
                     verificator->spoiled_left_jagajaga, verificator->spoiled_right_jagajaga};

        printf("Errors:\n");

        size_t array_size = sizeof(errors) / sizeof(errors[0]);

        size_t j = 0;

        while (j < array_size)
        {
            if (errors[j])
                printf(RED_COLOR "%s" DEFAULT_COLOR, OUTPUT_ERRORS[j]);

            j++;
        }
    }
}
