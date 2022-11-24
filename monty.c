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
 * cmd_exec - generate error
 * @fp: file pointer
 *
 * Return: void
 */

int cmd_exec(FILE *fp)
{
	stack_t *stack = NULL;
	ssize_t char_count;
	char  *line = NULL, **cmd;
	int line_count = 1;
	size_t n = 0;

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
			push(&stack, cmd, line_count, line, fp);
		else if (streq(cmd[0], "pall") == 0)
			pall(stack);
		else if (streq(cmd[0], "pint") == 0)
			pint(stack, line_count, cmd, line, fp);
		else if (streq(cmd[0], "pop") == 0)
			pop(&stack, line_count, cmd, line, fp);
		else if (streq(cmd[0], "swap") == 0)
			swap(&stack, line_count, cmd, line, fp);
		else if (streq(cmd[0], "add") == 0)
			add(&stack, line_count, cmd, line, fp);
		else if (streq(cmd[0], "sub") == 0)
			sub(&stack, line_count, cmd, line, fp);
		else if (streq(cmd[0], "div") == 0)
			divs(&stack, line_count, cmd, line, fp);
		else if (streq(cmd[0], "mul") == 0)
			muls(&stack, line_count, cmd, line, fp);
		else
			_error(cmd, line_count, line, fp, stack);
		line_count++, free_grid(cmd);
	}
	free(line), fclose(fp), free_stack(stack);
	return (0);
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
	FILE *fp;

	if (ac != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	fp = fopen(av[1], "r");
	if (fp != NULL)
		return (cmd_exec(fp));
	fprintf(stderr, "Error: Can't open file %s\n", av[1]), exit(EXIT_FAILURE);
}
