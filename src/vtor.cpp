#include <stdio.h>

#include "stack.h"
#include "vtor.h"


StackErrors stack_vtor(const Stack * stk)
{
    StackErrors verificator =         {};

    if (stk->size < 0)
        verificator.invalid_size =         true;
    if (stk->capacity < 0)
        verificator.invalid_capacity =     true;
    if (stk->size >= stk->capacity)
        verificator.invalid_sizecapacity = true;
    if (stk->data == nullptr)
        verificator.invalid_data =         true;

    return verificator;
}
