#include "monty.h"

/**
 * _error - generate error
 * @str: the string to check
 * @line_count: current line
 * @line: string in line
 * @fp: file pointer
 * @s: current stack
 *
 * Return: void
 */

void _error(char **str, int line_count, char *line, FILE *fp, stack_t *s)
{
	int ush_y, nop_y;

	ush_y = streq(str[0], "push"), nop_y = streq(str[0], "nop");
	if (ush_y == 0 && countstr(str) < 2)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_count);
		free(line), free_grid(str), fclose(fp);
		if (s != NULL)
			free_stack(s);
		exit(EXIT_FAILURE);
	}
	else if (ush_y != 0 && nop_y != 0 && str[0][0] != '#')
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_count, str[0]);
		free(line), free_grid(str), fclose(fp);
		if (s != NULL)
			free_stack(s);
		exit(EXIT_FAILURE);
	}
}
