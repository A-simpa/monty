#include "monty.h"

/**
 * pall - prints the elements in a double linked list
 * @h: the head of the double linked list
 *
 * Return: the length of the double linked list
 */

size_t pall(stack_t *h)
{
	size_t len = 0;

	if (h)
	{
		do {
			printf("%d\n", h->n);
			len++;
		} while ((h = h->next) != NULL);
	}
	return (len);
}
