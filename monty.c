#include "monty.h"

static instruction_t opcodes[] = {
    {"push", push},
    {"pall", pall},
    {NULL, NULL},
};
static stack_t **global_stack;

int main(int args, char **argv)
{
    stack_t *start;

    start = NULL, global_stack = &start;
    if (args != 2)
        write_err(1, "USAGE: monty file"), exit(EXIT_FAILURE);
    read_monty_file(argv[1]);
    return (0);
}

int read_monty_file(char *file_name)
{
    FILE *fp;
    char *opcode, buff[1024];
    unsigned int i;
    int res;

    fp = fopen(file_name, "r");
    if (!fp)
        write_err(2, "Error: Can't open file ", file_name), exit(EXIT_FAILURE);

    for (i = 1; _getline(buff, fp) != -1; i++)
    {
        opcode = strtok(buff, " \t\n");
        if (!opcode)
            continue;
        res = exec_opcode(opcode, i);
        if (res != 0)
            break;
    }
    free(buffer);
    fclose(fp);
    exit(res ? res : 0);
}

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
    selected_opcode->f(global_stack, line_number);
    return (0);
}

instruction_t *check_opcode(char *opcode)
{
    int i;

    for (i = 0; opcode && opcodes[i].opcode; i++)
        if (strcmp(opcode, opcodes[i].opcode) == 0)
            return (&opcodes[i]);

    return (NULL);
}