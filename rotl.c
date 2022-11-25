#include "monty.h"

/**
 * rotl - delete desired node
 * @s: the pointer to the first head
 *
 * Return: void
 */

void rotl(stack_t **s)
{
	stack_t *h = *s;

	if (*s != NULL)
	{
		if (stack_len(*s) == 1)
			return;
		*s = (*s)->next;
		(*s)->prev = NULL;
		stack_end(s, h);
	}
}
