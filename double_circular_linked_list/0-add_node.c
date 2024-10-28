#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * create_node - Crée un nouveau nœud et copie la chaîne de caractères.
 * @str: chaîne de caractères à copier dans le nœud.
 *
 * Return: un pointeur vers le nouveau nœud, ou NULL en cas d'échec.
 */
List *create_node(char *str)
{
	List *new_node = malloc(sizeof(List));

	if (!new_node)
		return (NULL);
	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	new_node->prev = new_node->next = NULL;
	return (new_node);
}

/**
 * add_node_end - Function that adds a node
 * @list: Pointeur vers le pointeur de la tête de la liste.
 * @str: Chaîne de caractères à ajouter dans le nouveau nœud.
 *
 * Return: Adresse du nouveau nœud, ou NULL en cas d'échec.
 */
List *add_node_end(List **list, char *str)
{
	List *new_node = create_node(str);

	if (!new_node)
		return (NULL);

	if (*list == NULL)
	{
		*list = new_node;
		new_node->next = new_node->prev = new_node;
	}
	else
	{
		List *tail = (*list)->prev;

		tail->next = new_node;
		new_node->prev = tail;
		new_node->next = *list;
		(*list)->prev = new_node;
	}
	return (new_node);
}

/**
 * add_node_begin - Adds a node
 * @list: Pointeur vers le pointeur de la tête de la liste.
 * @str: Chaîne de caractères à ajouter dans le nouveau nœud.
 *
 * Return: Adresse du nouveau nœud, ou NULL en cas d'échec.
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node = create_node(str);

	if (!new_node)
		return (NULL);

	if (*list == NULL)
	{
		*list = new_node;
		new_node->next = new_node->prev = new_node;
	}
	else
	{
		List *tail = (*list)->prev;

		new_node->next = *list;
		new_node->prev = tail;
		tail->next = new_node;
		(*list)->prev = new_node;
		*list = new_node;
	}
	return (new_node);
}
