#include "monty.h"

/**
 * push - add node to begginig of d linked list
 * @stack: head of the list
 * @line_number: int
 */
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

/**
 * pall - add node to begginig of d linked list
 * @stack: head of the list
 * @line_number: int
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	print_stack(*stack);
}

/**
 * pint - add node to begginig of d linked list
 * @stack: head of the list
 * @line_number: int
 */
void pint(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	char str_line_mumber[10];

	sprintf(str_line_mumber, "%d", line_number);
	if (!*stack)
	{
		write_err(3, "L", str_line_mumber, ": can't pint, stack empty");
		exit_program(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - add node to begginig of d linked list
 * @stack: head of the list
 * @line_number: int
 */
void pop(stack_t **stack, unsigned int line_number)
{
	char str_line_mumber[10];

	sprintf(str_line_mumber, "%d", line_number);
	if (!*stack)
	{
		write_err(3, "L", str_line_mumber, ": can't pop an empty stack");
		exit_program(EXIT_FAILURE);
	}
	del_stack_top(stack);
}

/**
 * swap - add node to begginig of d linked list
 * @stack: head of the list
 * @line_number: int
 */
void swap(stack_t **stack, unsigned int line_number)
{
	char str_line_mumber[10];
	stack_t *node_1, *node_2;

	sprintf(str_line_mumber, "%d", line_number);
	if (!*stack || !(*stack)->next)
	{
		write_err(3, "L", str_line_mumber, ": can't swap, stack too short");
		exit_program(EXIT_FAILURE);
	}
	node_1 = *stack, node_2 = (*stack)->next;
	node_2->prev = node_1->prev;
	node_1->prev = node_1->next;
	node_1->next = node_2->next;
	node_2->next = node_1;
	*stack = node_2;
}
