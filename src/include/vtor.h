#ifndef VTOR_H
    #define VTOR_H

    #include "stack.h"

    #define RED_COLOR "\x1b[31;1m"
    #define DEFAULT_COLOR "\x1b[0m"

    #define SHOW_DUMP(stk, verificator) show_dump(stk, #stk, verificator)

    struct StackErrors {
        bool invalid_size;
        bool invalid_capacity;
        bool invalid_sizecapacity;
        bool invalid_data;
    };

    StackErrors stack_vtor(const Stack * stk);
    void show_dump(const Stack * stk, const char * stack_name, const StackErrors * verificator);

#endif // VTOR_H
