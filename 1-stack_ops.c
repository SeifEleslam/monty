#include "monty.h"
/**
 * push_stack - add node to begginig of d linked list
 * @head: head of the list
 * @n: int
 * Return: new node
 */
stack_t *push_stack(stack_t **head, const int n)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
        return (NULL);

    new_node->n = n;
    new_node->next = *head;
    if (*head)
    {
        new_node->prev = (*head)->prev;
        if ((*head)->prev)
            (*head)->prev->next = new_node;
        (*head)->prev = new_node;
    }
    *head = new_node;

    return (new_node);
}

/**
 * print_stack - print d linked list
 * @h: head of the list
 * Return: len of the list
 */
size_t print_stack(const stack_t *h)
{
    stack_t *head;
    size_t len;

    len = 0;
    for (head = (stack_t *)h; head; head = head->next)
        printf("%d\n", head->n), len++;
    return (len);
}