#include "monty.h"

/**
 * swap - insert a node at an index of dlist
 * @s: the first node
 * @lc: the line count
 * @fp: the file pointer
 * @cmd: the cmd line
 * @line: the line
 *
 * Return: void
 */

void swap(stack_t **s, int lc, char **cmd, char *line, FILE *fp)
{
	stack_t *h = *s, *head;

	if (stack_len(*s) >= 2)
	{
		*s = (*s)->next;
		(*s)->prev = NULL;
		if (stack_len(*s) ==  1)
		{
			h->prev = h;
			h->next = NULL;
			(*s)->next = h;
		}
		else
		{
			head  = *s;
			head->prev = NULL;
			h->next = head->next;
			head->next = h;
			h->prev = head;
		}
		return;

	}
	fprintf(stderr, "L%d: can't swap, stack too short\n", lc);
	free(line), free_grid(cmd), free_stack(*s), fclose(fp);
	exit(EXIT_FAILURE);

}

