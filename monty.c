#include "monty.h"

/**
 * countstr - counting strings
 * @strs: strings to count
 *
 * Return: count of string
 */

int countstr(char **strs)
{
	int count = 0;

	while (strs[count])
	{
		count++;
	}
	return (count);
}

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
	int puall;

	puall = streq(str[0], "push");
	if (puall == 0 && countstr(str) < 2)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_count);
		free(line);
		free_grid(str), fclose(fp);
		if (s != NULL)
			free_stack(s);
		exit(EXIT_FAILURE);
	}
	else if (puall != 0 && streq(str[0], "pall") != 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_count, str[0]);
		free(line), free_grid(str), fclose(fp);
		if (s != NULL)
			free_stack(s);
		exit(EXIT_FAILURE);
	}
}


/**
 * main - entry point to the monty language
 * @ac: count of command line argument
 * @av: array of argument
 *
 * Return: 0 Always
 */


int main(int ac, char **av)
{
	stack_t *stack = NULL;
	FILE *fp;
	ssize_t char_count;
	char  *line = NULL, **cmd;
	int line_count = 1;
	size_t n = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (fp != NULL)
	{
		while ((char_count = getline(&line, &n, fp)) != -1)
		{
			if (*line == '\n' && ++line_count)
				continue;
			line[char_count - 1] = '\0', cmd = _strtok(line);
			if (countstr(cmd) == 0)
			{
				free_grid(cmd), line_count++;
				continue;
			}
			if (streq(cmd[0], "push") == 0)
			{
				_error(cmd, line_count, line, fp, stack);
				push(&stack, cmd, line_count, line, fp);
			}
			else if (streq(cmd[0], "pall") == 0)
				pall(stack);
			else
				_error(cmd, line_count, line, fp, stack);
			line_count++, free_grid(cmd);
		}
		free(line), fclose(fp), free_stack(stack);
		return (0);
	}
	fprintf(stderr, "Error: Can't open file %s\n", av[1]);
	exit(EXIT_FAILURE);
}
