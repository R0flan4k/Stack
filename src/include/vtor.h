#ifndef VTOR_H
    #define VTOR_H

    #include "stack.h"

    #define RED_COLOR "\x1b[31;1m"
    #define DEFAULT_COLOR "\x1b[0m"

    #define SHOW_DUMP(stk, verificator) show_dump(&stk, #stk, &verificator, __func__, __LINE__, __FILE__)

    const Error_t INVALID_SIZE =         1;
    const Error_t INVALID_CAPACITY =     2;
    const Error_t INVALID_SIZECAPACITY = 4;
    const Error_t INVALID_DATA =         8;

    struct StackErrors {
        Error_t error_code;

        bool invalid_size;
        bool invalid_capacity;
        bool invalid_sizecapacity;
        bool invalid_data;
    };

    StackErrors stack_vtor(const Stack * stk);
    void show_dump(const Stack * stk, const char * stack_name, const StackErrors * verificator, const char * func, const int line, const char * file);

#endif // VTOR_H
