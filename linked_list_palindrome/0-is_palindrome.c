#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * is_palindrome - Check if the singly linked list is a palindrome
 * @head: head of the linked list
 * Return: 1 if is palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *ptr = *head;
	listint_t *ptr2 = *head;
	int nb_elem = 0;
	int i = 0;

	while (ptr != NULL)
	{
		nb_elem++;
		ptr = ptr->next;
	}
	int tableau[nb_elem];
	int j = nb_elem;

	while (ptr2 != NULL)
	{
		tableau[i] = ptr2->n;
		ptr2 = ptr2->next;
		i++;
	}
	i = 0;

	while (i < nb_elem)
	{
		if (tableau[i] != tableau[j - 1])
		{
			return (0);
		}
		else
		{
			i++;
			j--;
		}
	}
	return (1);
}
