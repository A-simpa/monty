#include "monty.h"

/**
 *pchar - print the top of the stack
 *@h: the first node
 *@lc: the line count
 *@cmd: the command line
 *@line: the current
 *@fp: the file pointer
 *
 *Return: void
 */

void pchar(stack_t *h, int lc, char **cmd, char *line, FILE *fp)
{
	if (h != NULL)
	{
		if ((h->n) >= 0 && (h->n) <= 127)
		{
			printf("%c\n", h->n);
			return;
		}
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lc);
		free(line), free_grid(cmd), free_stack(h), fclose(fp);
		exit(EXIT_FAILURE);
	}
	fprintf(stderr, "L%d: can't pchar, stack empty\n", lc);
	free(line), free_grid(cmd), free_stack(h), fclose(fp);
	exit(EXIT_FAILURE);
}

