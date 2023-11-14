#include "monty.h"

static instruction_t opcodes[] = {
    {"push", push},
    {"pall", pall},
    {NULL, NULL},
};

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
    ssize_t bytes_read;
    size_t len;
    unsigned int i;
    char *buffer, *s1, *s2;
    int res;

    fp = fopen(file_name, "r");
    buffer = NULL, len = 0;
    if (!fp)
        write_err(2, "Error: Can't open file ", file_name), exit(EXIT_FAILURE);

    for (i = 1; (bytes_read = getline(&buffer, &len, fp)) != -1; i++)
    {
        buffer[strlen(buffer) - 1] = '\0';
        s1 = strtok(buffer, " "), s2 = strtok(NULL, " ");
        res = exec_opcode(s1, s2, i);
        if (res != 0)
            break;
    }
    free(buffer);
    fclose(fp);
    exit(res ? res : 0);
}

int exec_opcode(char *opcode, char *arg, unsigned int line_number)
{
    void (*func)(stack_t **stack, unsigned int line_number);
    char str_line_num[10];

    func = check_opcode(opcode);
    if (!func)
    {
        sprintf(str_line_num, "%d", line_number);
        write_err(4, "L", str_line_num, ": unknown instruction ", opcode);
        return (EXIT_FAILURE);
    }
    func(global_stack, str_to_int(arg));
    return (0);
}

void *check_opcode(char *opcode)
{
    int i;

    for (i = 0; opcodes[i].opcode; i++)
        if (strcmp(opcode, opcodes[i].opcode) == 0)
            return (opcodes[i].f);

    return (NULL);
}