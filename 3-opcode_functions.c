#include "monty.h"

/**
 * mod - add node to begginig of d linked list
 * @stack: head of the list
 * @line_number: int
 */
void mod(stack_t **stack, unsigned int line_number)
{
	char str_line_mumber[10];
	int sum;

	sprintf(str_line_mumber, "%d", line_number);
	if (!*stack || !(*stack)->next)
	{
		write_err(3, "L", str_line_mumber, ": can't mod, stack too short");
		exit_program(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		write_err(3, "L", str_line_mumber, ": division by zero");
		exit_program(EXIT_FAILURE);
	}
	sum = (*stack)->next->n % (*stack)->n;
	del_stack_top(stack);
	(*stack)->n = sum;
}
