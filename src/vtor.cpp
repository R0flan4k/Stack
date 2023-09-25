#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "vtor.h"
#include "my_assert.h"

Hash_t HASH_VALUE = 0;

const char * OUTPUT_ERRORS[] = {
    "Invlid size.\n",
    "Invalid capacity.\n",
    "Capacity less than size.\n",
    "Data is nullptr.\n",
    "Can't allocate a memory.\n",
    "Can't destruct destructed.\n",
    "Can't constrict the stack capacity.\n",
    "Can't pop an empty stack.\n",
    "Spoiled left canary.\n",
    "Spoiled right canary.\n",
    "Spoiled hash value.\n"
};


AllStackErrors stack_vtor(const Stack * stk)
{
    AllStackErrors verificator = {
        .invalid_size =           {.expression = (stk->size < 0),                         .mask = STACKERRORS_INVALID_SIZE},
        .invalid_capacity =       {.expression = (stk->capacity < 0),                     .mask = STACKERRORS_INVALID_CAPACITY},
        .invalid_sizecapacity =   {.expression = (stk->size >= stk->capacity),            .mask = STACKERRORS_INVALID_SIZECAPACITY},
        .invalid_data =           {.expression = (stk->data == nullptr),                  .mask = STACKERRORS_INVALID_DATA},
        .spoiled_left_jagajaga =  {.expression = (stk->left_jagajaga != JAGAJAGA_VALUE),  .mask = STACKERRORS_SPOILED_LEFT_JAGAJAGA},
        .spoiled_right_jagajaga = {.expression = (stk->right_jagajaga != JAGAJAGA_VALUE), .mask = STACKERRORS_SPOILED_RIGHT_JAGAJAGA},
        .spoiled_hash_value =     {.expression = (stk->hash != HASH_VALUE),               .mask = STACKERRORS_SPOILED_HASH_VALUE}
    };

    StackError * stack_errors[] = {&(verificator.invalid_size),          &(verificator.invalid_capacity),
                                   &(verificator.invalid_sizecapacity),  &(verificator.invalid_data),
                                   &(verificator.spoiled_left_jagajaga), &(verificator.spoiled_right_jagajaga),
                                   &(verificator.spoiled_hash_value)};

    size_t array_size = sizeof(stack_errors) / sizeof(stack_errors[0]);
    size_t i = 0;

    while (i < array_size)
    {
        if (stack_errors[i]->expression)
            verificator.error_code |= stack_errors[i]->mask;

        i++;
    }

    // HASH_VALUE = stk->hash;

    return verificator;
}


void show_dump(const Stack * stk, const char * stack_name, const AllStackErrors * verificator, const char * func, const int line, const char * file)
{
    printf("-------------------------------------------------------------------\n");
    printf("Stack[%p] \"%s\" from %s(%d), %s\n", stk, stack_name, file, line, func);
    printf("{\n");
    printf("    size =     %d%s\n", stk->size,     stk->size == POISON     ? "(POISON)" : "");
    printf("    capacity = %d%s\n", stk->capacity, stk->capacity == POISON ? "(POISON)" : "");
    printf("    data[%p%s]\n", stk->data,          stk->data == POISON_PTR ? "(POISON)" : "");
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
                                   &(verificator->spoiled_left_jagajaga), &(verificator->spoiled_right_jagajaga),
                                   &(verificator->spoiled_hash_value)};

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

    printf("-------------------------------------------------------------------\n");
}
