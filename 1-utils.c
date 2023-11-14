#include "monty.h"

/**
 * str_to_int - handle signals
 * @s: str
 * Return: int
 */
int str_to_int(char *s)
{
    int result, i;

    result = 0, i = 0;
    if (!s || s[i] == '-')
        return (-1);
    while (s[i] != '\0')
    {
        if (s[i] < '0' || s[i] > '9')
            return (-1);
        result *= 10;
        result += s[i] - '0';
        i++;
    }
    return (result);
}
