#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: pointer to a pointer to the first node of the list
 * @idx: index of the node to insert
 * @n: data for the new node
 *
 * Return: address of the new node, or NULL on failure
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 0;
	listint_t *new, *temp;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	temp = *head;
	while (i < idx - 1)
	{
		if (temp == NULL)
		{
			free(new);
			return (NULL);
		}
		temp = temp->next;
		i++;
	}

	new->next = temp->next;
	temp->next = new;

	return (new);
}
