#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
    push_stack(stack, line_number);
}

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    print_stack(*stack);
}