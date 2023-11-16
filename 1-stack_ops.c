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
	new_node->prev = NULL;
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
 * add_to_queue - add node to end of d linked list
 * @head: head of the list
 * @n: int
 * Return: new node
 */
stack_t *add_to_queue(stack_t **head, const int n)
{
	stack_t *new_node;
	stack_t *curr;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return (NULL);

	for (curr = *head; curr && curr->next;)
		curr = curr->next;
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = curr;
	if (!*head)
		*head = new_node;
	else
		curr->next = new_node;
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

/**
 * del_stack_top - print d linked list
 * @h: head of the list
 * Return: len of the list
 */
void del_stack_top(stack_t **h)
{
	stack_t *head;

	head = *h;
	*h = (*h)->next;
	if (*h)
		(*h)->prev = NULL;
	free(head);
}

/**
 * free_stack - add node to end of d linked list
 * @head: head of the list
 * Return: new node
 */
void free_stack(stack_t *head)
{
	if (head)
		free_stack(head->next), free(head);
}
