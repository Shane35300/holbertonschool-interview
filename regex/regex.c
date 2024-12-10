#include "regex.h"

/**
 * regex_match - Vérifie si un motif correspond à une chaîne donnée
 * @str: La chaîne à analyser
 * @pattern: L'expression régulière
 *
 * Return: 1 si le motif correspond à la chaîne, sinon 0
 */
int regex_match(const char *str, const char *pattern)
{
if (*pattern == '\0')
return (*str == '\0');

int first_match = (*str && (*str == *pattern || *pattern == '.'));

if (*(pattern + 1) == '*')
{
return (regex_match(str, pattern + 2) ||
(first_match && regex_match(str + 1, pattern)));
}
else
{
return (first_match && regex_match(str + 1, pattern + 1));
}
}
