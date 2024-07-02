#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "palindrome.h"

/**
 * is_palindrome - name of the function
 * @n: number to analyze
 * Return: 1 or 0
 */

int is_palindrome(unsigned long n)
{
	char array[21];
	int x = 0, y;

	sprintf(array, "%lu", n);
	x = strlen(array);
	for (y = 0; y < x / 2; y++)
	{
		if (array[y] != array[x - 1 - y])
		{
			return 0;
		}
	}
	return (1);
}
