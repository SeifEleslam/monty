#include "monty.h"

/**
 * str_to_int - handle signals
 * @s: str
 * Return: int
 */
int str_to_int(char *s)
{
    int result, sign, i;

    result = 0, sign = 1, i = 0;
    if (s[i] == '-')
        sign = -1, i++;
    while (s[i] != '\0')
    {
        if (s[i] < '0' || s[i] > '9')
            return (-1);
        result *= 10;
        result += s[i] - '0';
        i++;
    }
    return (result * sign);
}

/**
 * is_int - handle signals
 * @s: str
 * Return: int
 */
int is_int(char *s)
{
    int i;

    i = 0;
    if (s && s[0] == '-')
        i++;
    while (s && s[i] != '\0')
    {
        if (s[i] < '0' || s[i] > '9')
            return (1);
        i++;
    }
    return (0);
}

int _getline(char *line, FILE *fp)
{
    char *ptr;
    int ch;

    ptr = line;
    while ((ch = fgetc(fp)) != EOF && ch != '\n')
        *ptr++ = (char)ch;

    if (ch == EOF)
        return (-1);

    *ptr = '\0';
    return 0;
}