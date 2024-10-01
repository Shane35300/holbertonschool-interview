#include <unistd.h>
#include "holberton.h"

/**
 * _putchar - Écrit le caractère c sur la sortie standard.
 * @c: Le caractère à imprimer.
 *
 * Return: 1 en cas de succès.
 * En cas d'erreur, -1 est renvoyé et errno est défini de manière appropriée.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
