#include "monty.h"

/**
 *stack_end - add an int to the end ddlist
 *@head: the head of the double linked list
 *@new: the new stack to add
 *
 *Return: the pointer to the new added int
 */

void stack_end(stack_t **head, stack_t *new)
{
	stack_t *h;

	h = *head;
	if (*head)
	{
		while (h->next != NULL)
		{
			h = h->next;
		}
	}
	new->prev = h;
	new->next = NULL;

	if (h)
		(h)->next = new;
	else
		*head = new;

	return;

}

