#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
    char *arg, str_line_mumber[10];
    int val;

    arg = strtok(NULL, " \t\n");
    if (is_int(arg) != 0)
    {
        sprintf(str_line_mumber, "%d", line_number);
        write_err(3, "L", str_line_mumber, ": usage: push integer");
        exit(EXIT_FAILURE);
    }
    val = atoi(arg);
    push_stack(stack, val);
}

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    print_stack(*stack);
}