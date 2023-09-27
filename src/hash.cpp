#include <stdio.h>
#include <math.h>

#include "stack.h"

#ifndef NHASHPOTECTION

    Hash_t calculate_hash(Stack * stk, const size_t size)
    {
        char * pointer = (char *) stk;
        char * end_pointer = (char *) stk + size - 1;
        Hash_t hash = 0;
        double value = 2;

        while (pointer < end_pointer)
        {
            hash += (Hash_t) (pow(value, (double) (end_pointer - pointer)) * (*pointer));

            pointer++;
        }

        return hash;
    }

    Hash_t recalculate_hash(Stack * stk, const size_t size)
    {
        stk->hash = 0;

        return calculate_hash(stk, size);
    }

#else // NHASHPROTECTION

    Hash_t calculate_hash(Stack * stk, const size_t size)
    {
        return (Hash_t) 0;
    }


    Hash_t recalculate_hash(Stack * stk, const size_t size)
    {
        return (Hash_t) 0;
    }

#endif // NHASHPOTECTION
