#include "lists.h"

/**
 * add_nodeint_end - returns a new node after adding node at end
 * @head: head pointer of the list used to dereference head
 * @n: the integer value to be added
 *
 * Return: the address of the new pointer
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newnode, *current = *head;

	/*allocating a space for the new node*/

	newnode = (listint_t *) malloc(sizeof(listint_t));
	/*checking if malloc fails*/

	if (newnode == NULL)
	{
		return (NULL);
	}
	/*allocating values to the new node using the returned pointer*/
	newnode->n = n;
	newnode->next = NULL;

	/*checking if the list exist*/
	if (*head == NULL)
	{
		newnode->next = NULL;
		*head = newnode;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = newnode;
	}
	return (newnode);
}
