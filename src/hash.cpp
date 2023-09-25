#include <stdio.h>

#include "stack.h"

#ifndef NHASHPOTECTION

    Hash_t calculate_hash(Stack * stk)
    {
        Hash_t data_hash = 0;
        int i = 0;

        while (i < (int) (stk->size * sizeof(Elem_t) - 1))
        {
            data_hash += ((char *) stk->data)[i] * ((char *) stk->data)[i + 1];

            i++;
        }

        return (stk->size * stk->capacity) + (stk->capacity * data_hash) + ((int) data_hash * stk->size);
    }

#else // NHASHPROTECTION

    Hash_t calculate_hash(Stack * stk)
    {
        return (Hash_t) 0;
    }

#endif // NHASHPOTECTION
