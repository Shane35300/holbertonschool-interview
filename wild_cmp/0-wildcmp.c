#include "holberton.h"

/**
 * wildcmp - Compares two strings and checks if they can be considered identica
 * @s1: The first string
 * @s2: The second string, which can include the wildcard '*'
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
if (*s2 == '\0')
	return (*s1 == '\0');

if (*s2 == '*')
{
	if (*(s2 + 1) == '\0')
		return (1);
	if (*s1 == '\0')
		return (wildcmp(s1, s2 + 1));
	return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
}

if (*s1 == *s2)
	return (wildcmp(s1 + 1, s2 + 1));

return (0);
}
