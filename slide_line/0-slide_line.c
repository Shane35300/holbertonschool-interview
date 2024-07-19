#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers to the left or right.
 * @line: Pointer to an array of integers.
 * @size: Number of elements in @line.
 * @direction: SLIDE_LEFT or SLIDE_RIGHT.
 * Return: 1 on success, 0 on failure.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_LEFT)
		slide_left(line, size);
	else if (direction == SLIDE_RIGHT)
		slide_right(line, size);

	return (1);
}

/**
 * slide_left - Slides and merges an array of integers to the left.
 * @line: Pointer to an array of integers.
 * @size: Number of elements in @line.
 */
void slide_left(int *line, size_t size)
{
	int i, j;

	for (i = 0, j = 0; i < (int)size; i++)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j++;
		}
	}

	for (i = 0; i < (int)size - 1; i++)
	{
		if (line[i] == line[i + 1] && line[i] != 0)
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
	}

	for (i = 0, j = 0; i < (int)size; i++)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j++;
		}
	}
}

/**
 * slide_right - Slides and merges an array of integers to the right.
 * @line: Pointer to an array of integers.
 * @size: Number of elements in @line.
 */
void slide_right(int *line, size_t size)
{
	int i, j;

	for (i = (int)size - 1, j = (int)size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j--;
		}
	}

	for (i = (int)size - 1; i > 0; i--)
	{
		if (line[i] == line[i - 1] && line[i] != 0)
		{
			line[i] *= 2;
			line[i - 1] = 0;
		}
	}

	for (i = (int)size - 1, j = (int)size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j--;
		}
	}
}
