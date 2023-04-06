#include "lists.h"
/**
 * insert_nodeint_at_index - inserts a newnode in a linked list,
 * at a required position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is to be added
 * @n: data to be inserted in the newnode
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int k;
listint_t *newnode;
listint_t *current = *head;

newnode = (listint_t *) malloc(sizeof(listint_t));

/*checking if malloc fials*/
if (!new || !head)
return (NULL);

/*asigning int and a pointer to the newly allocated space*/
newnode->n = n;
newnode->next = NULL;

/*checking if index is 0*/
if (idx == 0)
{
newnode->next = *head;
*head = newnode;
return (newnode);
}

for (k = 0; current && k < idx; k++)
{
if (k == idx - 1)
{
newnode->next = current->next;
current->next = newnode;
return (newnode);
}
else
current = current->next;
}

return (NULL);
}
