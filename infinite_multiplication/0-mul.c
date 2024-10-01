#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

#define ERROR_MESSAGE "Error\n"

/**
 * _print_error - Prints error message and exits with status 98.
 */
void _print_error(void)
{
	int i = 0;
	while (ERROR_MESSAGE[i])
	{
		_putchar(ERROR_MESSAGE[i]);
		i++;
	}
	exit(98);
}

/**
 * is_digit - Checks if a string consists only of digits.
 * @s: The string to check.
 *
 * Return: 1 if true, otherwise 0.
 */
int is_digit(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _calloc - Allocates memory for an array and initializes it to 0.
 * @nmemb: Number of elements.
 * @size: Size of each element.
 *
 * Return: Pointer to allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *arr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	arr = malloc(nmemb * size);
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		arr[i] = '0';

	return (arr);
}

/**
 * main - Multiplies two positive numbers.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	char *num1, *num2, *result;
	int len1, len2, len_res, i, j, carry, prod;

	if (argc != 3)
		_print_error();

	num1 = argv[1];
	num2 = argv[2];

	if (!is_digit(num1) || !is_digit(num2))
		_print_error();

	len1 = 0;
	len2 = 0;

	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	len_res = len1 + len2;
	result = _calloc(len_res, sizeof(char));
	if (result == NULL)
		_print_error();

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			prod = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
			carry = prod / 10;
			result[i + j + 1] = (prod % 10) + '0';
		}
		result[i + j + 1] += carry;
	}

	i = 0;
	while (i < len_res && result[i] == '0')
		i++;

	if (i == len_res)
		_putchar('0');
	else
	{
		while (i < len_res)
			_putchar(result[i++]);
	}

	_putchar('\n');
	free(result);
	return (0);
}
