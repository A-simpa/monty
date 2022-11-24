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
	int all_y, ush_y, int_y, op_y;

	ush_y = streq(str[0], "push"), all_y = streq(str[0], "pall");
	int_y = streq(str[0], "pint"), op_y = streq(str[0], "pop");
	if (ush_y == 0 && countstr(str) < 2)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_count);
		free(line), free_grid(str), fclose(fp);
		if (s != NULL)
			free_stack(s);
		exit(EXIT_FAILURE);
	}
	else if (all_y != 0 && ush_y != 0 && int_y != 0 && op_y != 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_count, str[0]);
		free(line), free_grid(str), fclose(fp);
		if (s != NULL)
			free_stack(s);
		exit(EXIT_FAILURE);
	}
}
