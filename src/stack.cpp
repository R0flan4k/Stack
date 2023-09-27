#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "vtor.h"
#include "my_assert.h"

static int expand_memory(Stack * stk);
static int constrict_memory(Stack * stk);


AllStackErrors stack_ctor(Stack * stk)
{
    Elem_t * data = NULL;
    AllStackErrors errors = {};

    if (!stack_vtor(stk).error_code)
    {
        errors.cant_construct.expression = true;
        errors.error_code |= STACKERRORS_CANT_CONSTRUCT;

        return errors;
    }

    stk->size = 0;
    stk->capacity = STACK_START_CAPACITY;
    stk->left_jagajaga = STACK_JAGAJAGA_VALUE;
    stk->right_jagajaga = STACK_JAGAJAGA_VALUE;
    stk->hash = 0;


    if ((data = (Elem_t *) calloc(STACK_START_CAPACITY * sizeof(Elem_t) + 2 * sizeof(Jagajaga_t), sizeof(char))) == NULL)
    {
        stk->data = nullptr;

        errors.cant_allocate_memory.expression = true;
        errors.error_code |= STACKERRORS_CANT_ALLOCATE_MEMORY;

        return errors;
    }

    stk->data = (Elem_t *) ((Jagajaga_t *) data + 1);

    HASH_VALUE = calculate_hash(stk, sizeof(Stack));
    stk->hash = HASH_VALUE;
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

    if (stk->data == nullptr && stk->capacity == STACK_POISON && stk->size == STACK_POISON)
    {
        errors.cant_destruct.expression = true;
        errors.error_code |= STACKERRORS_CANT_DESTRUCT;

        return errors;
    }

    stk->capacity = STACK_POISON;
    stk->size =     STACK_POISON;
    stk->hash =     STACK_POISON;

    free((Jagajaga_t *) stk->data - 1);
    stk->data = nullptr;

    return errors;
}


AllStackErrors stack_push(Stack * stk, const Elem_t value)
{
    stk->hash = recalculate_hash(stk, sizeof(Stack));

    AllStackErrors errors = stack_vtor(stk);

    if (errors.error_code)
    {
        show_dump(stk, &errors);

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

    HASH_VALUE = recalculate_hash(stk, sizeof(Stack));
    stk->hash = HASH_VALUE;

    return errors;
}


AllStackErrors stack_pop(Stack * stk, Elem_t * value)
{
    stk->hash = recalculate_hash(stk, sizeof(Stack));

    AllStackErrors errors = stack_vtor(stk);

    if (errors.error_code)
    {
        return errors;
    }

    if (stk->size > 0)
    {
        *value = stk->data[stk->size];
        stk->data[stk->size] = STACK_POISON;
        (stk->size)--;

        if (stk->size <= stk->capacity / STACK_CONSTRICT_COEFFICIENT && stk->capacity > STACK_START_CAPACITY)
        {
            MY_ASSERT(stk->size == stk->capacity / STACK_CONSTRICT_COEFFICIENT);

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

    HASH_VALUE = recalculate_hash(stk, sizeof(Stack));
    stk->hash = HASH_VALUE;

    return errors;
}


static int expand_memory(Stack * stk)
{
    Elem_t * pointer = NULL;

    if ((pointer = (Elem_t *) realloc((Jagajaga_t *) stk->data - 1, (stk->capacity * sizeof(Elem_t)) * STACK_EXPAND_COEFFICIENT + (2 * sizeof(Jagajaga_t)))) == NULL)
        return 1;

    stk->data = (Elem_t *) ((Jagajaga_t *) pointer + 1);
    stk->capacity *= STACK_EXPAND_COEFFICIENT;

    return 0;
}


static int constrict_memory(Stack * stk)
{
    Elem_t * pointer = NULL;

    if ((pointer = (Elem_t *) realloc((Jagajaga_t *) stk->data - 1, (stk->capacity * sizeof(Elem_t)) / STACK_EXPAND_COEFFICIENT + (2 * sizeof(Jagajaga_t)))) == NULL)
        return 1;

    stk->data = (Elem_t *) ((Jagajaga_t *) pointer + 1);
    stk->capacity /= STACK_EXPAND_COEFFICIENT;

    return 0;
}
