#include "lists.h"

/**
 * add_nodeint - adds a new node at the front
 * @head: the pointer to the first elements of the list
 * @n: the integer to be added
 *
 * Return: the address of the new node or null if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *newnode;

newnode = (listint_t *) malloc(sizeof(listint_t));
/* checking if malloc fails */
if (newnode == NULL)
return (newnode);
/*Asigning int and pointers to the allocated space */
newnode->n = n;
newnode->next = NULL;

/*checking if the list even exists */
if (*head == NULL)
{
newnode->next = NULL;
*head = newnode;
return (newnode);
}
else
{
newnode->next = *head;
*head = newnode;
return (newnode);
}
return (newnode);
}

