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


void push(stack_t **h, char **n_list, int lc, char *line, FILE *fp)
{
	char **list = n_list + 1;

	_error(n_list, lc, line, fp, *h);
	if (numcheck(list[0]) == 0)
	{
		free(line);
		free_grid(n_list), fclose(fp);
		if (*h != NULL)
			free_stack(*h);
		fprintf(stderr, "L%d: usage: push integer\n", lc);
		exit(EXIT_FAILURE);
	}
	add_stack(h, _atoi(list[0]));
}
