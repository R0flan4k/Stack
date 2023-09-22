#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "vtor.h"

int main(void)
{
    Stack stk = {};

    StackErrors errors = {};

    if ((errors = stack_ctor(&stk)).error_code)
        SHOW_DUMP(&stk, &errors);

    free(stk.data);
    stk.data = nullptr;

    printf("%p", stk.data);

    return 0;
}
