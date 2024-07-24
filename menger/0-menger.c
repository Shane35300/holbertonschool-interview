#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * is_filled - Check if a position should be filled.
 * @row: The row index of the position.
 * @col: The column index of the position.
 * Return: 1 if the position should be filled, 0 otherwise.
 */
int is_filled(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (1);
		row /= 3;
		col /= 3;
	}

	return (0);
}


/**
 * menger - Draw a 2D Menger Sponge of a given level.
 * @level: The level of the Menger Sponge to draw.
 */
void menger(int level)
{
	int size, i, j, result;

	if (level < 0)
		return;
	size = pow(3, level);

	for (j = 0 ; j < size ; j++)
	{
		for (i = 0 ; i < size ; i++)
		{
			result = is_filled(i, j);
			if (result == 0)
				printf("#");
			if (result == 1)
				printf(" ");
			if (i == (size - 1))
				printf("\n");
		}
	}
}
