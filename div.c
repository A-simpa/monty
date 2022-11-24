#include "monty.h"

/**
 * divs - sub the top from the next node
 * @s: the pointer to the first head
 * @lc: the line count
 * @cmd: the command line
 * @line: the current
 * @fp: the file pointer
 *
 * Return: void
 */

void divs(stack_t **s, int lc, char **cmd, char *line, FILE *fp)
{
	int sum = 0;
	stack_t *h = *s;

	if (stack_len(*s) >= 2)
	{
		if ((*s)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", lc);
			free(line), free_grid(cmd), free_stack(*s), fclose(fp);
			exit(EXIT_FAILURE);
		}
		h = h->next;
		sum = (h->n) / ((*s)->n);
		pop(s, lc, cmd, line,  fp);
		pop(s, lc, cmd, line, fp);
		add_stack(s, sum);
		return;
	}
	fprintf(stderr, "L%d: can't div, stack too short\n", lc);
	free(line), free_grid(cmd), free_stack(*s), fclose(fp);
	exit(EXIT_FAILURE);
}
