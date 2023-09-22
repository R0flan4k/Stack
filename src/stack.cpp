#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "vtor.h"

StackErrors stack_ctor(Stack * stk)
{
    stk->size = 0;
    stk->capacity = START_CAPACITY;

    Elem_t * data = NULL;

    if ((data = (Elem_t *) calloc(START_CAPACITY, sizeof(Elem_t))) == NULL)
    {
        printf("Can't allocate a memory.\n");

        stk->data = nullptr;
    }

    stk->data = data;

    StackErrors errors = stack_vtor(stk);

    if(errors.error_code)
    {
        SHOW_DUMP(stk, &errors);
    }

    return errors;
}


DtorSuccess stack_dtor(Stack * stk)
{
    DtorSuccess destructor = SUCCESSFUL_DESTRUCT;

    if (stk->data == nullptr)
    {
        destructor = FAILURE_DESTRUCT;
    }
    else
    {
        stk->capacity = POISON;
        stk->size =     POISON;

        free(stk->data);
        stk->data = nullptr;
    }

    return destructor;
}
