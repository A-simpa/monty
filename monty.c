#include "monty.h"
#include <stdio.h>

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
 * main - entry point to the monty language
 * @ac: count of command line argument
 * @av: array of argument
 *
 * Return: 0 Always
 */


int main(int ac, char **av)
{
	stack_t *stack;
	FILE *fp;
	ssize_t char_count;
	char  *line = NULL, **cmd;
	int line_count = 1, puall;
	size_t n = 0;

	stack = NULL;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (fp != NULL)
	{
		while (1)
		{
			char_count = getline(&line, &n, fp);
			if (char_count == -1)
				break;
			if (line[char_count - 1] == '\n')
				line[char_count - 1] = '\0';
			cmd = _strtok(line);
			puall = streq(cmd[0], "push");
			if ((countstr(cmd) != 2 || atoi(cmd[1]) < 0) && puall == 0)
			{
				printf("L%d: usage: push integer\n", line_count);
				exit(EXIT_FAILURE);
			}

			if (streq(cmd[0], "push") == 0)
				push(&stack, atoi(cmd[1]));
			if (streq(cmd[0], "pall") == 0)
				pall(stack);
			line_count++;
		}
		free(line);
		free(cmd);
		fclose(fp);
		return (0);
	}
	printf("Error: Can't open file %s\n", av[1]);
	exit(EXIT_FAILURE);
}
