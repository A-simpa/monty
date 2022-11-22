#include "monty.h"

/**
 * streq - compares two strings
 * @str1: the first string
 * @str2: the second string
 *
 * Return: 0 or 1
 */


int streq(char *str1, char *str2)
{
	int len1, i = 0;

	len1 = in_len(str1);
	if (len1 != in_len(str2))
		return (1);

	while (i < len1)
	{
		if (str1[i] !=  str2[i])
			return (1);
		i++;
	}
	return (0);
}
