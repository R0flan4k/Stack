#ifndef STACK_H
    #define STACK_H

    typedef double Elem_t;
    typedef int Error_t;
    typedef long long Jagajaga_t;
    typedef long long Hash_t;

    #define ELEM_SPEC "%lf"

    enum StackErrorsMasks {
        STACKERRORS_INVALID_SIZE =                1 << 0,
        STACKERRORS_INVALID_CAPACITY =            1 << 1,
        STACKERRORS_INVALID_SIZECAPACITY =        1 << 2,
        STACKERRORS_INVALID_DATA =                1 << 3,
        STACKERRORS_CANT_ALLOCATE_MEMORY =        1 << 4,
        STACKERRORS_CANT_CONSTRUCT =              1 << 5,
        STACKERRORS_CANT_DESTRUCT =               1 << 6,
        STACKERRORS_CANT_CONSTRICT =              1 << 7,
        STACKERRORS_EMPTY_STACK =                 1 << 8,
        STACKERRORS_SPOILED_LEFT_JAGAJAGA =       1 << 9,
        STACKERRORS_SPOILED_RIGHT_JAGAJAGA =      1 << 10,
        STACKERRORS_SPOILED_DATA_LEFT_JAGAJAGA =  1 << 11,
        STACKERRORS_SPOILED_DATA_RIGHT_JAGAJAGA = 1 << 12,
        STACKERRORS_SPOILED_HASH_VALUE =          1 << 13,
        STACKERRORS_SPOILED_DATA_HASH_VALUE =     1 << 14
    };

    enum StackResizes {
        STACK_EXPAND,
        STACK_CONSTRICT
    };

    struct StackError {
        StackErrorsMasks mask;
        const char * output_error;
    };

    struct Stack {
        Jagajaga_t left_jagajaga;
        int size;
        int capacity;
        Elem_t * data;
        Hash_t hash;
        Hash_t data_hash;
        Jagajaga_t right_jagajaga;
    };

    const int STACK_START_CAPACITY = 16;
    const int STACK_POISON = 0x70FEEFEE;
    const int STACK_EXPAND_COEFFICIENT = 2;
    const int STACK_CONSTRICT_COEFFICIENT = 4;
    Elem_t * const STACK_POISON_PTR = NULL;
    const Jagajaga_t STACK_JAGAJAGA_VALUE = 0xAB00B1EABCDEF;

    Error_t stack_ctor(Stack * stk);
    Error_t stack_dtor(Stack * stk);
    Error_t stack_push(Stack * stk, const Elem_t value);
    Error_t stack_pop (Stack * stk, Elem_t * value);
    Hash_t calculate_hash(void * stk, const size_t size);
    Hash_t stack_recalculate_hash(Stack * stk, const size_t size);
    Jagajaga_t * stack_get_data_left_jagajaga(const Stack * stk);
    Jagajaga_t * stack_get_data_right_jagajaga(const Stack * stk);
    Elem_t * stack_data_to_raw(Stack * stk);
    Elem_t * stack_raw_to_data(void * data);

#endif // STACK_H
