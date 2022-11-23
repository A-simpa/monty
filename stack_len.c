#include "monty.h"

/**
 * stack_len - the length of the linked list
 * @h: the head of the double linked list
 *
 * Return: the length of the double linked list
 */

size_t stack_len(stack_t *h)
{
	size_t len = 0;

	if (h)
	{
		do {
			len++;
		} while ((h = h->next) != NULL);
	}
	return (len);
}
