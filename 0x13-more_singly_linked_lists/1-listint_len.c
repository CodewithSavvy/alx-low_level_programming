#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked lists
 * @h: head pointer of the list
 *
 * Return: the number of nodes
 */

size_t listint_len(const listint_t *h)
{
size_t n = 0;

while (h)
{
h = h->next;
n++;
}
return (n);
}

