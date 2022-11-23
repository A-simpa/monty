#include "monty.h"

/**
 *pint - get the top of the stack
 *@h: the first node
 *@lc: the line count
 *@cmd: the command line
 *@line: the current
 *@fp: the file pointer
 *
 *Return: void
 */

void pint(stack_t *h, int lc, char **cmd, char *line, FILE *fp)
{
	if (h != NULL)
	{
		printf("%d\n", h->n);
		return;
	}
	fprintf(stderr, "L%d: can't pint, stack empty\n", lc);
	free(line), free_grid(cmd), free_stack(h), fclose(fp);
	exit(EXIT_FAILURE);
}

