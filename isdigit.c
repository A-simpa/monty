#include "monty.h"

/**
* _isdigit - To check if digit
* @c: c is the character to check for value
* Return: int (Sucess)
*/


int _isdigit(char c)
{

	if ((c > 47 && c < 58) || (c == 43 || c == 45))
	{
		return (1);
	}
	else
	{
		return (0);

	}
}
