#ifndef CMD_INPUT_H
    #define CMD_INPUT_H

    #include "stack.h"

    struct CmdLineArg {
        const char * name;                           ///< Name of flag.
        int num_of_param;                            ///< Number of flag parameters.
        void (*flag_function)(void);                 ///< Function of flag.
        int argc_number;                             ///< Serial number of flag in cmd line.
        const char * help;                           ///< How to use this flag.
    };

    extern CmdLineArg STACK_PUSH;

    extern Elem_t PUSH_NUMBER;

    bool check_cmd_input(int argc, char * * argv);
    void set_flag_stack_push(void);

#endif // CMD_INPUT_H
