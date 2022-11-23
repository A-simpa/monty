#include "monty.h"

/**
 *free_stack - frees a dlist
 *@head: the first node
 *
 *Return: void
 */

void free_stack(stack_t *head)
{
	stack_t *h;
	size_t len, count, times;

	if (head)
	{
		count = 0, len = stack_len(head) - 1;
		while (count < len)
		{
			h = head;
			times = len - count;
			do {
				h = h->next;
			} while ((--times) > 0);
			free(h);
			count++;
		}
	}
	free(head);
}

