#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * topple_cell - Topple a single cell in the sandpile
 * @grid: The sandpile grid
 * @i: Row index of the cell
 * @j: Column index of the cell
 */
static void topple_cell(int grid[3][3], int i, int j)
{
	grid[i][j] -= 4;
	if (i > 0)
		grid[i - 1][j] += 1;
	if (i < 2)
		grid[i + 1][j] += 1;
	if (j > 0)
		grid[i][j - 1] += 1;
	if (j < 2)
		grid[i][j + 1] += 1;
}

/**
 * is_unstable - Check if the sandpile is unstable
 * @grid: The sandpile grid
 * Return: 1 if unstable, 0 if stable
 */
static int is_unstable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				return (1);
			}
		}
	}
	return (0);
}

/**
 * stabilize_grid - Stabilize the sandpile grid
 * @grid: The sandpile grid
 */
static void stabilize_grid(int grid[3][3])
{
	int unstable;

	do {
		unstable = is_unstable(grid);

		if (unstable)
		{
			printf("=\n");
			print_grid(grid);
			/* Create a copy of grid to store changes */
			int temp_grid[3][3] = {0};
			int i, j;

			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					temp_grid[i][j] = grid[i][j];
				}
			}
			/* Topple the cells */
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (grid[i][j] > 3)
					{
						topple_cell(temp_grid, i, j);
					}
				}
			}
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					grid[i][j] = temp_grid[i][j];
				}
			}
		}
	} while (unstable);
}

/**
 * sandpiles_sum - Compute the sum of two sandpiles
 * @grid1: First sandpile (will hold the result)
 * @grid2: Second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Add grid2 to grid1 */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	stabilize_grid(grid1);
}
