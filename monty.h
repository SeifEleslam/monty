
#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct global_s
{
	stack_t *stack;
	FILE *fp;
} global_t;

extern global_t global_var;

/* functions */
void *_realloc(void *ptr, int old_size, int new_size);
void read_monty_file(char *file_name);
void write_err(int n, ...);
int str_to_int(char *s);
int is_int(char *s);
int _getline(char *line, FILE *fp);
instruction_t *check_opcode(char *opcode);
int exec_opcode(char *line, unsigned int line_number);
void exit_program(int status_code);

/* operations */
stack_t *push_stack(stack_t **head, const int n);
size_t print_stack(const stack_t *h);
void del_stack_top(stack_t **h);
void free_stack(stack_t *head);

/* opcodes functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

#endif
