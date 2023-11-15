#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
    char *arg, str_line_mumber[10];
    int val;

    arg = strtok(NULL, " \t\n");
    sprintf(str_line_mumber, "%d", line_number);
    if (!arg || is_int(arg) != 0)
    {
        write_err(3, "L", str_line_mumber, ": usage: push integer");
        exit_program(EXIT_FAILURE);
    }
    val = atoi(arg);
    if (!push_stack(stack, val))
        write_err(1, "Error: malloc failed"), exit_program(EXIT_FAILURE);
}

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    print_stack(*stack);
}