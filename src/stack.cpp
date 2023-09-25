#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "vtor.h"
#include "my_assert.h"


AllStackErrors stack_ctor(Stack * stk)
{
    stk->size = 0;
    stk->capacity = START_CAPACITY;
    stk->left_jagajaga = JAGAJAGA_VALUE;
    stk->right_jagajaga = JAGAJAGA_VALUE;

    Elem_t * data = NULL;
    AllStackErrors errors = {};

    if ((data = (Elem_t *) calloc(START_CAPACITY * sizeof(Elem_t) + 2 * sizeof(Jagajaga_t), sizeof(char))) == NULL)
    {
        stk->data = nullptr;

        errors.cant_allocate_memory.expression = true;
        errors.error_code |= STACKERRORS_CANT_ALLOCATE_MEMORY;

        return errors;
    }

    stk->data = (Elem_t *) ((Jagajaga_t *) data + 1);

    HASH_VALUE = calculate_hash(stk);
    errors = stack_vtor(stk);

    if(errors.error_code)
    {
        return errors;
    }

    return errors;
}


AllStackErrors stack_dtor(Stack * stk)
{
    AllStackErrors errors = {};

    if (stk->data == nullptr && stk->capacity == POISON && stk->size == POISON)
    {
        errors.cant_destruct.expression = true;
        errors.error_code |= STACKERRORS_CANT_DESTRUCT;
    }
    else
    {
        stk->capacity = POISON;
        stk->size =     POISON;
        stk->hash =     POISON;

        free((Jagajaga_t *) stk->data - 1);
        stk->data = nullptr;
    }

    return errors;
}


AllStackErrors stack_push(Stack * stk, const Elem_t value)
{
    stk->hash = calculate_hash(stk);
    AllStackErrors errors = stack_vtor(stk);

    if (errors.error_code)
    {
        SHOW_DUMP(stk, &errors);

        return errors;
    }

    (stk->size)++;

    if (stk->size >= stk->capacity)
    {
        MY_ASSERT(stk->size == stk->capacity);

        if (expand_memory(stk))
        {
            errors.cant_allocate_memory.expression = true;
            errors.error_code |= STACKERRORS_CANT_ALLOCATE_MEMORY;

            return errors;
        }
    }

    stk->data[stk->size] = value;

    HASH_VALUE = calculate_hash(stk);

    return errors;
}


AllStackErrors stack_pop(Stack * stk, Elem_t * value)
{
    stk->hash = calculate_hash(stk);
    AllStackErrors errors = stack_vtor(stk);

    if (errors.error_code)
    {
        return errors;
    }

    if (stk->size > 0)
    {
        *value = stk->data[stk->size];
        stk->data[stk->size] = POISON;
        (stk->size)--;

        if (stk->size <= stk->capacity / EXPAND_COEFFICIENT && stk->capacity > START_CAPACITY)
        {
            MY_ASSERT(stk->size == stk->capacity / EXPAND_COEFFICIENT);

            if (constrict_memory(stk))
            {
                errors.cant_constrict.expression = true;
                errors.error_code |= STACKERRORS_CANT_CONSTRICT;

                return errors;
            }
        }
    }
    else
    {
        errors.empty_stack.expression = true;
        errors.error_code |= STACKERRORS_EMPTY_STACK;
    }

    HASH_VALUE = stk->hash;

    return errors;
}


int expand_memory(Stack * stk)
{
    Elem_t * pointer = NULL;

    if ((pointer = (Elem_t *) realloc((Jagajaga_t *) stk->data - 1, (stk->capacity * sizeof(Elem_t)) * EXPAND_COEFFICIENT + (2 * sizeof(Jagajaga_t)))) == NULL)
        return 1;

    stk->data = (Elem_t *) ((Jagajaga_t *) pointer + 1);
    stk->capacity *= EXPAND_COEFFICIENT;

    return 0;
}


int constrict_memory(Stack * stk)
{
    Elem_t * pointer = NULL;

    if ((pointer = (Elem_t *) realloc((Jagajaga_t *) stk->data - 1, (stk->capacity * sizeof(Elem_t)) / EXPAND_COEFFICIENT + (2 * sizeof(Jagajaga_t)))) == NULL)
        return 1;

    stk->data = (Elem_t *) ((Jagajaga_t *) pointer + 1);
    stk->capacity /= EXPAND_COEFFICIENT;

    return 0;
}
