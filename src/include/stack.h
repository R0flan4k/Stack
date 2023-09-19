#ifndef STACK_H
    #define STACK_H

    typedef int Elem_t;

    struct Stack {
        unsigned int size;
        unsigned int capacity;
        Elem_t * data;
    };

    enum StackErrors {
        OK,
        INVALID_SIZE,
        INVALID_CAPACITY,
        INVALID_SIZE_AND_CAPACITY,
        SIZE_CAPACITY_ERROR,
        NULLPTR_DATA_ERROR
    };

#endif // STACK_H
