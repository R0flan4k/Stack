#ifndef STACK_H
    #define STACK_H

    typedef double Elem_t;
    typedef int Error_t;
    typedef long long Jagajaga_t;
    typedef long long Hash_t;

    #define ELEM_SPEC "%lf"

    #define STACK_CTOR(stk, errors)         if ((*(errors) = stack_ctor(stk)).error_code)             \
                                            {                                                         \
                                                SHOW_DUMP((stk), (errors));                           \
                                                return (*(errors)).error_code;                        \
                                            }                                                         \
                                            else                                                      \
                                            {                                                         \
                                                printf("The stack successfully created.\n");          \
                                            }                                                         \

    #define STACK_DTOR(stk, errors)         if ((*(errors) = stack_dtor(stk)).error_code)             \
                                            {                                                         \
                                                SHOW_DUMP((stk), (errors));                           \
                                                return (*(errors)).error_code;                        \
                                            }                                                         \
                                            else                                                      \
                                            {                                                         \
                                                printf("The stack successfully destructed.\n");       \
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

    enum StackErrorsMasks {
        STACKERRORS_INVALID_SIZE =           1 << 0,
        STACKERRORS_INVALID_CAPACITY =       1 << 1,
        STACKERRORS_INVALID_SIZECAPACITY =   1 << 2,
        STACKERRORS_INVALID_DATA =           1 << 3,
        STACKERRORS_CANT_ALLOCATE_MEMORY =   1 << 4,
        STACKERRORS_CANT_DESTRUCT =          1 << 5,
        STACKERRORS_CANT_CONSTRICT =         1 << 6,
        STACKERRORS_EMPTY_STACK =            1 << 7,
        STACKERRORS_SPOILED_LEFT_JAGAJAGA =  1 << 8,
        STACKERRORS_SPOILED_RIGHT_JAGAJAGA = 1 << 9,
        STACKERRORS_SPOILED_HASH_VALUE =     1 << 10
    };

    struct StackError {
        bool expression;
        StackErrorsMasks mask;
    };

    struct AllStackErrors {
        Error_t error_code;

        StackError invalid_size;
        StackError invalid_capacity;
        StackError invalid_sizecapacity;
        StackError invalid_data;
        StackError cant_allocate_memory;
        StackError cant_destruct;
        StackError cant_constrict;
        StackError empty_stack;
        StackError spoiled_left_jagajaga;
        StackError spoiled_right_jagajaga;
        StackError spoiled_hash_value;
    };

    struct Stack {
        Jagajaga_t left_jagajaga;
        int size;
        int capacity;
        Elem_t * data;
        Hash_t hash;
        Jagajaga_t right_jagajaga;
    };

    const int START_CAPACITY = 16;
    const int POISON = 0x5051EB10; // hexspeak
    const int EXPAND_COEFFICIENT = 2;
    const int CONSTRICT_COEFFICIENT = 4;
    Elem_t * const POISON_PTR = NULL;
    const Jagajaga_t JAGAJAGA_VALUE = 0xAB00B1E;

    extern Hash_t HASH_VALUE;

    AllStackErrors stack_ctor(Stack * stk);
    AllStackErrors stack_dtor(Stack * stk);
    AllStackErrors stack_push(Stack * stk, const Elem_t value);
    AllStackErrors stack_pop (Stack * stl, Elem_t * value);
    int expand_memory(Stack * stk);
    int constrict_memory(Stack * stk);
    Hash_t calculate_hash(Stack * stk);

#endif // STACK_H

// prishel za minutu do konca pari xD
