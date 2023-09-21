#ifndef STACK_H
    #define STACK_H

    typedef int Elem_t;
    typedef char Error_t;

    struct Stack {
        int size;
        int capacity;
        Elem_t * data;
    };

#endif // STACK_H
