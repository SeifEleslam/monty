#include "monty.h"

/**
 * stack - add node to begginig of d linked list
 * @stack: head of the list
 * @line_number: int
 */
void stack(__attribute__((unused)) stack_t **stack,
		   __attribute__((unused)) unsigned int line_number)
{
	global_var.type = 's';
}

/**
 * queue - add node to begginig of d linked list
 * @stack: head of the list
 * @line_number: int
 */
void queue(__attribute__((unused)) stack_t **stack,
		   __attribute__((unused)) unsigned int line_number)
{
	global_var.type = 'q';
}
