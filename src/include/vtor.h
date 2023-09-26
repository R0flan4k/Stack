#ifndef VTOR_H
    #define VTOR_H

    #include "stack.h"

    #define RED_COLOR "\x1b[31;1m"
    #define DEFAULT_COLOR "\x1b[0m"

    #define show_dump(stk, verificator) show_dump_basis((stk), #stk, (verificator), __func__, __LINE__, __FILE__)

    AllStackErrors stack_vtor(const Stack * stk);
    void show_dump_basis(const Stack * stk, const char * stack_name, const AllStackErrors * verificator, const char * func, const int line, const char * file);

#endif // VTOR_H
