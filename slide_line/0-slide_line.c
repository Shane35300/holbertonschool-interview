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
		return 0;

	if (direction == SLIDE_LEFT)
	{
		int i, current = 0, merged = 0;

		for (i = 0; i < (int)size; i++)
		{
			if (line[i] != 0)
			{
				if (current != i)
				{
					if (line[current] == line[i] && merged == 0)
					{
						line[current++] *= 2;
						line[i] = 0;
						merged = 1;
					}
					else if (line[current] == 0)
					{
						line[current] = line[i];
						line[i] = 0;
					}
					else
					{
						if (line[current + 1] == 0)
							current++;
						line[++current] = line[i];
						if (i != current)
							line[i] = 0;
					}
				}
				else
					merged = 0;
			}
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		int i, current = size - 1, merged = 0;

		for (i = size - 1; i >= 0; i--)
		{
			if (line[i] != 0)
			{
				if (current != i)
				{
					if (line[current] == line[i] && merged == 0)
					{
						line[current--] *= 2;
						line[i] = 0;
						merged = 1;
					}
					else if (line[current] == 0)
					{
						line[current] = line[i];
						line[i] = 0;
					}
					else
					{
						if (line[current - 1] == 0)
							current--;
						line[--current] = line[i];
						if (i != current)
							line[i] = 0;
					}
				}
				else
					merged = 0;
			}
		}
	}
	return 1;
}
