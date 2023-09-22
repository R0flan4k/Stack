#ifndef STACK_H
    #define STACK_H

    typedef int Elem_t;
    typedef char Error_t;

    #define ELEM_SPEC "%d"

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

    struct Stack {
        int size;
        int capacity;
        Elem_t * data;
    };

    enum DtorSuccess {
        SUCCESSFUL_DESTRUCT,
        FAILURE_DESTRUCT
    };

    const int START_CAPACITY = 16;
    const int POISON = 2147483647;
    Elem_t * const POISON_PTR = NULL;

    StackErrors stack_ctor(Stack * stk);
    DtorSuccess stack_dtor(Stack * stk);

#endif // STACK_H
