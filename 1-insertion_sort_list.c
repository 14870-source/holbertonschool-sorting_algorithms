#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Pointer to the head of the list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *insert;
	listint_t *next;
	listint_t *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;
		insert = current;

		while (insert->prev != NULL && insert->prev->n > insert->n)
		{
			prev = insert->prev;

			insert->prev = prev->prev;
			prev->next = insert->next;

			if (insert->next != NULL)
				insert->next->prev = prev;

			insert->next = prev;
			prev->prev = insert;

			if (insert->prev != NULL)
				insert->prev->next = insert;
			else
				*list = insert;

			print_list(*list);
		}

		current = next;
	}
}
