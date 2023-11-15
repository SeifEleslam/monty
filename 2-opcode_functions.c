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
	del_stack_top(stack);
	(*stack)->n = sum;
}

/**
 * nop - add node to begginig of d linked list
 * @stack: head of the list
 * @line_number: int
 */
void nop(__attribute__((unused)) stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
}

/**
 * sub - add node to begginig of d linked list
 * @stack: head of the list
 * @line_number: int
 */
void sub(stack_t **stack, unsigned int line_number)
{
	char str_line_mumber[10];
	int sum;

	sprintf(str_line_mumber, "%d", line_number);
	if (!*stack || !(*stack)->next)
	{
		write_err(3, "L", str_line_mumber, ": can't sub, stack too short");
		exit_program(EXIT_FAILURE);
	}
	sum = (*stack)->next->n - (*stack)->n;
	del_stack_top(stack);
	(*stack)->n = sum;
}