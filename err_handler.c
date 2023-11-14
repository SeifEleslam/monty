#include "monty.h"

void write_err(int n, ...)
{
    char err_msg[1024];
    int i;
    va_list msgs;

    va_start(msgs, n);
    for (i = 0, err_msg[0] = '\0'; i < n; i++)
        strcat(err_msg, va_arg(msgs, char *));
    strcat(err_msg, "\n");
    write(STDERR_FILENO, err_msg, strlen(err_msg));
}