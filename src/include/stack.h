#ifndef STACK_H
    #define STACK_H

    typedef double Elem_t;
    typedef int Error_t;
    typedef long long Jagajaga_t;
    typedef long long Hash_t;

    #define ELEM_SPEC "%lf"

    enum StackErrorsMasks {
        STACKERRORS_INVALID_SIZE =           1 << 0,
        STACKERRORS_INVALID_CAPACITY =       1 << 1,
        STACKERRORS_INVALID_SIZECAPACITY =   1 << 2,
        STACKERRORS_INVALID_DATA =           1 << 3,
        STACKERRORS_CANT_ALLOCATE_MEMORY =   1 << 4,
        STACKERRORS_CANT_CONSTRUCT =         1 << 5,
        STACKERRORS_CANT_DESTRUCT =          1 << 6,
        STACKERRORS_CANT_CONSTRICT =         1 << 7,
        STACKERRORS_EMPTY_STACK =            1 << 8,
        STACKERRORS_SPOILED_LEFT_JAGAJAGA =  1 << 9,
        STACKERRORS_SPOILED_RIGHT_JAGAJAGA = 1 << 10,
        STACKERRORS_SPOILED_HASH_VALUE =     1 << 11
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
        StackError cant_construct;
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

    const int STACK_START_CAPACITY = 16;
    const int STACK_POISON = 0x70FEEFEE;
    const int STACK_EXPAND_COEFFICIENT = 2;
    const int STACK_CONSTRICT_COEFFICIENT = 4;
    Elem_t * const STACK_POISON_PTR = NULL;
    const Jagajaga_t STACK_JAGAJAGA_VALUE = 0xAB00B1EABCDEF;

    extern Hash_t HASH_VALUE;

    AllStackErrors stack_ctor(Stack * stk);
    AllStackErrors stack_dtor(Stack * stk);
    AllStackErrors stack_push(Stack * stk, const Elem_t value);
    AllStackErrors stack_pop (Stack * stl, Elem_t * value);
    Hash_t calculate_hash(Stack * stk, const size_t size);
    Hash_t recalculate_hash(Stack * stk, const size_t size);

#endif // STACK_H
