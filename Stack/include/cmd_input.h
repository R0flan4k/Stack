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
    extern FILE * INPUT_FILE;
    extern FILE * OUTPUT_ERROR_FILE;

    bool check_cmd_input(int argc, char * * argv);

#endif // CMD_INPUT_H
