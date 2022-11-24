#include "monty.h"

/**
 * pstr - prints the elements in a stack string
 * @head: the head of the double linked list
 *
 * Return: the length of the double linked list
 */

void pstr(stack_t *head)
{
	stack_t *h = head;

	if (h)
	{
		do {
			if ((h->n) > 0 && (h->n) <= 127)
				printf("%c\n", h->n);
			else
				return;
		} while ((h = h->next) != NULL);
		return;
	}
	printf("\n");
}
