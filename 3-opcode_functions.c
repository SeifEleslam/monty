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

/**
 * pchar - add node to begginig of d linked list
 * @stack: head of the list
 * @line_number: int
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	char str_line_mumber[10];

	sprintf(str_line_mumber, "%d", line_number);
	if (!*stack)
	{
		write_err(3, "L", str_line_mumber, ": can't pchar, stack empty");
		exit_program(EXIT_FAILURE);
	}
	else if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		write_err(3, "L", str_line_mumber, ": can't pchar, value out of range");
		exit_program(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - add node to begginig of d linked list
 * @stack: head of the list
 * @line_number: int
 */
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *curr = *stack;

	for (; curr; curr = curr->next)
		if (curr->n < 1 || curr->n > 127)
			putchar(curr->n);
		else
			break;
	putchar('\n');
}