#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - name of the function
 * @n: number to analyze
 * Return: 1 or 0
 */

int is_palindrome(unsigned long n)
{
	char array[21];
	int x = 0, y = 0;

	sprintf(array, "%lu", n);
	while (array[x] != '\0')
	{
		x++;
	}
	x -= 1;
	while (x > y)
	{
		if (array[x] - 48 != array[y] - 48)
			return (0);
		x--;
		y++;
	}
	return (1);
}
