#include "monty.h"

/**
 * _realloc - allocate memory and set to 0
 * @ptr: unsigned int
 * @old_size: unsigned int
 * @new_size: unsigned int
 * Return: void*
 */
void *_realloc(void *ptr, int old_size, int new_size)
{
    char *newptr;
    int i;

    if (new_size == old_size)
        return (ptr);
    if (ptr == NULL)
    {
        newptr = malloc(new_size);
        if (newptr == NULL)
            return (NULL);
        return (newptr);
    }
    if (new_size == 0)
    {
        free(ptr);
        return (NULL);
    }

    newptr = malloc(new_size);
    if (newptr == NULL)
        return (NULL);
    if (ptr == NULL)
        return (newptr);
    for (i = 0; i < old_size && i < new_size; i++)
        newptr[i] = ((char *)ptr)[i];
    free(ptr);
    return (newptr);
}