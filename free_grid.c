#include "monty.h"

/**
*free_grid - frees a 2d array
*@grid: 2d array
*
*Return: void
*/

void free_grid(char **grid)
{
int k = 0;

int height = countstr(grid);

while (k < height)
{
	free(grid[k]);
	k++;
}
free(grid);
}

