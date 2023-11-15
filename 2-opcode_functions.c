#include "monty.h"

/**
 * add - add node to begginig of d linked list
 * @stack: head of the list
 * @line_number: int
 */
void add(stack_t **stack, unsigned int line_number)
{
	char str_line_mumber[10];
	int sum;

	sprintf(str_line_mumber, "%d", line_number);
	if (!*stack || !(*stack)->next)
	{
		write_err(3, "L", str_line_mumber, ": can't add, stack too short");
		exit_program(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	del_stack_top(stack), del_stack_top(stack);
	if (!push_stack(stack, sum))
		write_err(1, "Error: malloc failed"), exit_program(EXIT_FAILURE);
}
