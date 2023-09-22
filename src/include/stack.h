#ifndef STACK_H
    #define STACK_H

    typedef int Elem_t;
    typedef int Error_t;

    #define ELEM_SPEC "%d"
    #define STACK_CTOR(stk, errors)         if ((*(errors) = stack_ctor(stk)).error_code)             \
                                            {                                                         \
                                                SHOW_DUMP((stk), (errors));                           \
                                                return (*(errors)).error_code;                        \
                                            }                                                         \

    #define STACK_DTOR(stk, errors)         if ((*(errors) = stack_dtor(stk)).error_code)             \
                                            {                                                         \
                                                SHOW_DUMP((stk), (errors));                           \
                                                return (*(errors)).error_code;                        \
                                            }                                                         \

    #define STACK_PUSH(stk, value, errors)  if ((*(errors) = stack_push((stk), (value))).error_code)  \
                                            {                                                         \
                                                SHOW_DUMP((stk), (errors));                           \
                                                return (*(errors)).error_code;                        \
                                            }                                                         \

    #define STACK_POP(stk, value, errors)   if ((*(errors) = stack_pop((stk), (value))).error_code)   \
                                            {                                                         \
                                                SHOW_DUMP((stk), (errors));                           \
                                                return (*(errors)).error_code;                        \
                                            }                                                         \

    enum Errors {
        STACKERRORS_INVALID_SIZE =         1 << 0,
        STACKERRORS_INVALID_CAPACITY =     1 << 1,
        STACKERRORS_INVALID_SIZECAPACITY = 1 << 2,
        STACKERRORS_INVALID_DATA =         1 << 3,
        STACKERRORS_CANT_ALLOCATE_MEMORY = 1 << 4,
        STACKERRORS_CANT_DESTRUCT =        1 << 5,
        STACKERRORS_CANT_CONSTRICT =       1 << 6,
        STACKERRORS_EMPTY_STACK =          1 << 7
    };

    struct StackErrors {
        Error_t error_code;

        bool invalid_size;
        bool invalid_capacity;
        bool invalid_sizecapacity;
        bool invalid_data;
        bool cant_allocate_memory;
        bool cant_destruct;
        bool cant_constrict;
        bool empty_stack;
    };

    struct Stack {
        int size;
        int capacity;
        Elem_t * data;
    };

    const int START_CAPACITY = 16;
    const int POISON = 2147483647; // hexspeak
    const int EXPAND_COEFFICIENT = 2;
    Elem_t * const POISON_PTR = NULL;

    StackErrors stack_ctor(Stack * stk);
    StackErrors stack_dtor(Stack * stk);
    StackErrors stack_push(Stack * stk, const Elem_t value);
    StackErrors stack_pop (Stack * stl, Elem_t * value);
    int expand_memory(Stack * stk);
    int constrict_memory(Stack * stk);

#endif // STACK_H
