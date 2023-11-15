#include "monty.h"

static instruction_t opcodes[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{NULL, NULL},
};

/**
 * main - add node to begginig of d linked list
 * @args: head of the list
 * @argv: int
 * Return: 0
 */

int main(int args, char **argv)
{
	global_var.stack = NULL;
	if (args != 2)
		write_err(1, "USAGE: monty file"), exit(EXIT_FAILURE);
	read_monty_file(argv[1]);
	return (0);
}

/**
 * read_monty_file - add node to begginig of d linked list
 * @file_name: head of the list
 */
void read_monty_file(char *file_name)
{
	char *opcode, buff[1024];
	unsigned int i;
	int res;

	global_var.fp = fopen(file_name, "r");
	if (!global_var.fp)
		write_err(2, "Error: Can't open file ", file_name), exit(EXIT_FAILURE);

	for (i = 1; _getline(buff, global_var.fp) != -1; i++)
	{
		opcode = strtok(buff, " \t\n");
		if (!opcode)
			continue;
		res = exec_opcode(opcode, i);
		if (res != 0)
			break;
	}
	exit_program(res ? res : 0);
}

/**
 * exec_opcode - add node to begginig of d linked list
 * @opcode: head of the list
 * @line_number: int
 * Return: exit status
 */
int exec_opcode(char *opcode, unsigned int line_number)
{
	instruction_t *selected_opcode;
	char str_line_num[10];

	selected_opcode = check_opcode(opcode);
	if (!selected_opcode)
	{
		sprintf(str_line_num, "%d", line_number);
		write_err(4, "L", str_line_num, ": unknown instruction ", opcode);
		return (EXIT_FAILURE);
	}
	selected_opcode->f(&(global_var.stack), line_number);
	return (0);
}

/**
 * check_opcode - add node to begginig of d linked list
 * @opcode: head of the list
 * Retrun: the selected instruction
 */
instruction_t *check_opcode(char *opcode)
{
	int i;

	for (i = 0; opcode && opcodes[i].opcode; i++)
		if (strcmp(opcode, opcodes[i].opcode) == 0)
			return (&opcodes[i]);

	return (NULL);
}

/**
 * exit_program - add node to begginig of d linked list
 * @status_code: head of the list
 */
void exit_program(int status_code)
{
	free_stack(global_var.stack);
	fclose(global_var.fp);
	exit(status_code);
}
