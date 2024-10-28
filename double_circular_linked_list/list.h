#ifndef LIST_H
#define LIST_H
#include <stddef.h>

/**
 * struct List - liste doublement chaînée circulaire
 * @str: chaîne de caractères (allocuée dynamiquement)
 * @prev: pointeur vers le nœud précédent
 * @next: pointeur vers le nœud suivant
 *
 * Description: structure d'un nœud de liste doublement chaînée circulaire
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

/* Prototypes des fonctions */
List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);

#endif /* LIST_H */
