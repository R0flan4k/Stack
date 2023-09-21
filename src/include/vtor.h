#ifndef VTOR_H
    #define VTOR_H

    #include "stack.h"

    #define STACK_VTOR(stk)

    struct StackErrors {
        bool invalid_size;
        bool invalid_capacity;
        bool invalid_sizecapacity;
        bool invalid_data;
    };

    StackErrors stack_vtor(const Stack * stk);

#endif // VTOR_H
