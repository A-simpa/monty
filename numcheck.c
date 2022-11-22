#include "monty.h"

/**
 * numcheck - check if a number
 * @str: string
 *
 * Return: 0 and 1
 */


int numcheck(char *str)
{
	int ind = 0;

	while (str[ind] != '\0')
	{
		if (_isdigit(str[ind++]) == 0)
			return (0);
	}
	return (1);
}
