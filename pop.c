#include "monty.h"

/**
 * pop - delete desired node
 * @s: the pointer to the first head
 * @lc: the line count
 * @cmd: the command line
 * @line: the current
 * @fp: the file pointer
 *
 * Return: void
 */

void pop(stack_t **s, int lc, char **cmd, char *line, FILE *fp)
{
	stack_t *h = *s;

	if (*s != NULL)
	{
		if (stack_len(*s) == 1)
		{
			*s = NULL;
			free(h);
			return;
		}
		*s = (*s)->next;
		(*s)->prev = NULL;
		free(h);
		return;
	}
	fprintf(stderr, "L%d: can't pop an empty stack\n", lc);
	free(line), free_grid(cmd), free_stack(*s), fclose(fp);
	exit(EXIT_FAILURE);
}
