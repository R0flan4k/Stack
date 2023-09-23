#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "vtor.h"
#include "my_assert.h"


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
    StackErrors verificator = {
        .invalid_size =           {.expression = (stk->size < 0),                         .mask = STACKERRORS_INVALID_SIZE},
        .invalid_capacity =       {.expression = (stk->capacity < 0),                     .mask = STACKERRORS_INVALID_CAPACITY},
        .invalid_sizecapacity =   {.expression = (stk->size >= stk->capacity),            .mask = STACKERRORS_INVALID_SIZECAPACITY},
        .invalid_data =           {.expression = (stk->data == nullptr),                  .mask = STACKERRORS_INVALID_DATA},
        .spoiled_left_jagajaga =  {.expression = (stk->left_jagajaga != JAGAJAGA_VALUE),  .mask = STACKERRORS_SPOILED_LEFT_JAGAJAGA},
        .spoiled_right_jagajaga = {.expression = (stk->right_jagajaga != JAGAJAGA_VALUE), .mask = STACKERRORS_SPOILED_RIGHT_JAGAJAGA}
    };

    StackError * stack_errors[] = {&(verificator.invalid_size),          &(verificator.invalid_capacity),
                                   &(verificator.invalid_sizecapacity),  &(verificator.invalid_data),
                                   &(verificator.spoiled_left_jagajaga), &(verificator.spoiled_right_jagajaga)};

    size_t array_size = sizeof(stack_errors) / sizeof(stack_errors[0]);
    size_t i = 0;

    while (i < array_size)
    {
        if (stack_errors[i]->expression)
            verificator.error_code |= stack_errors[i]->mask;

        i++;
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
    StackError const * errors[] = {&(verificator->invalid_size),          &(verificator->invalid_capacity),
                                   &(verificator->invalid_sizecapacity),  &(verificator->invalid_data),
                                   &(verificator->cant_allocate_memory),  &(verificator->cant_destruct),
                                   &(verificator->cant_constrict),        &(verificator->empty_stack),
                                   &(verificator->spoiled_left_jagajaga), &(verificator->spoiled_right_jagajaga)};

        printf("Errors:\n");

        size_t array_size = sizeof(errors) / sizeof(errors[0]);
        size_t j = 0;

        MY_ASSERT(array_size == sizeof(OUTPUT_ERRORS) / sizeof(OUTPUT_ERRORS[0]));

        while (j < array_size)
        {
            if (errors[j]->expression)
                printf(RED_COLOR "%s" DEFAULT_COLOR, OUTPUT_ERRORS[j]);

            j++;
        }
    }
}
