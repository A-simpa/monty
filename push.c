#include "monty.h"

/**
 * push - add an integer to the begining
 * @n: the integer to add at the front
 * @head: pointer to the head of the dlist
 *
 * Return: the address of the new int
 */

stack_t *push(stack_t **head, unsigned int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free(new);
		fprintf(stderr, "malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->prev = NULL;
	new->n = n;
	if (*head)
	{
		(*head)->prev = new;
	}
	new->next = *head;
	*head = new;
	return (new);
}

