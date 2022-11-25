#include "monty.h"

/**
 * add_stack - add an integer to the begining
 * @n: the integer to add at the front
 * @head: pointer to the head of the dlist
 *
 * Return: the address of the new int
 */

stack_t *add_stack(stack_t **head, unsigned int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free(new);
		fprintf(stderr, "malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->prev = NULL;
	new->n = n;
	if (*head)
	{
		(*head)->prev = new;
	}
	new->next = *head;
	*head = new;
	return (new);
}

/**
 * push - add an integer to the begining
 * @n_list: the list of command
 * @h: pointer to the head of the dlist
 * @lc: line count
 * @line: current line
 * @fp: file pointer
 *
 * Return: the address of the new int
 */


void push(stack_t **h, char **cmd, int lc, char *line, FILE *fp, int q)
{
	char **list = cmd + 1;
	stack_t *up;

	_error(cmd, lc, line, fp, *h);
	if (numcheck(list[0]) == 0)
	{
		free(line);
		free_grid(cmd), fclose(fp);
		if (*h != NULL)
			free_stack(*h);
		fprintf(stderr, "L%d: usage: push integer\n", lc);
		exit(EXIT_FAILURE);
	}
	if (q == 0)
		add_stack(h, _atoi(list[0]));
	else if (q == 1)
	{
		up = malloc(sizeof(stack_t));
		if (up == NULL)
		{
			free(up);
			fprintf(stderr, "malloc failed\n");
			exit(EXIT_FAILURE);
		}
		up->n = _atoi(list[0]);
		stack_end(h, up);
	}
}
