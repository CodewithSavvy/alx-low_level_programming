#include "lists.h"

/**
 * free_listint2 - to free a linked list in listint_t
 * @head: pointer to the first node to be freed
 *
 * Return: absolutely nothing
 */
void free_listint2(listint_t **head)
{
	listint_t *current = *head;
	/*chcking if the list even exist*/
	if (head == NULL)
		return;
	while (current)
	{
		current = current->next;
		free(*head);
		*head = current;
	}
	*head = NULL;
}
