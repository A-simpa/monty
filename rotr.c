#include "monty.h"

/**
 * rotr - prints the elements in a double linked list
 * @head: the head of the double linked list
 *
 * Return: the length of the double linked list
 */

void rotr(stack_t **head)
{
	size_t i = 0;
	size_t len = stack_len(*head);

	if (head)
	{
		while (i < len - 1)
		{
			rotl(head), i++;
		}
	}
}
