#ifndef STACK_H
    #define STACK_H

    typedef int Elem_t;
    typedef char Error_t;

    #define ELEM_SPEC "%d"

    struct Stack {
        int size;
        int capacity;
        Elem_t * data;
    };

    const int START_CAPACITY = 16;

#endif // STACK_H
