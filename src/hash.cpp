#include <stdio.h>

#include "hash.h"


Hash_t calculate_hash(Stack * stk)
{
    Hash_t data_hash = 0;
    size_t i = 0;

    while (i < stk->size * sizeof(Elem_t) - 1)
    {
        data_hash += ((char *) stk->data)[i] % ((char *) stk->data)[i + 1];

        i++;
    }

    return (stk->size % stk->capacity) + (stk->capacity % data_hash) + (data_hash % stk->size);
}
