#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "vtor.h"

int main(void)
{
    Stack stk = {.size =     -1,
                 .capacity = -100,
                 .data =     nullptr};

//     Elem_t * data1 = NULL;
//
//     if ((data1 = (Elem_t *) calloc(stk.capacity, sizeof(Elem_t))) == NULL)
//     {
//         printf("Can't allocate a memory\n");
//         return 1;
//     }
//
//     stk.data = data1;

    StackErrors errors = stack_vtor(&stk);

    SHOW_DUMP(&stk, &errors);

    return 0;
}
