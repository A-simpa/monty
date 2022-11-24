#include "monty.h"

/**
 * add - add the top of the stack
 * @s: the pointer to the first head
 * @lc: the line count
 * @cmd: the command line
 * @line: the current
 * @fp: the file pointer
 *
 * Return: void
 */

void add(stack_t **s, int lc, char **cmd, char *line, FILE *fp)
{
	int sum = 0, len = 0;
	stack_t *h = *s;

	if (stack_len(*s) >= 2)
	{
		while (len < 2)
		{
			sum += h->n;
			h = h->next, len++;
		}

		pop(s, lc, cmd, line,  fp);
		pop(s, lc, cmd, line, fp);
		add_stack(s, sum);
		return;
	}
	fprintf(stderr, "L%d: cant add, stack to short\n", lc);
	free(line), free_grid(cmd), free_stack(*s), fclose(fp);
	exit(EXIT_FAILURE);
}
