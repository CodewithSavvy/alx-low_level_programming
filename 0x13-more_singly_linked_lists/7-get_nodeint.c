#include "lists.h"
/**
 * get_nodeint_at_index - the node at a certain index in a linked list
 * @head: first node in the list
 * @index: index of the node to return
 *
 * Return: pointer to the node , or NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int n = 0;
listint_t *current = head;

/*using temp to travers through the list to the index node tobe return*/
while (current && n < index)
{
current = current->next;
n++;
}

return (current ? current : NULL);
}
