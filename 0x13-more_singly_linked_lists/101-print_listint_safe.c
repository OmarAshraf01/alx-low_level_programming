#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the start of the list
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;
	const listint_t *array[1024];
	size_t i, count = 0;

	while (current != NULL)
	{
		for (i = 0; i < count; i++)
		{
			if (current == array[i])
			{
				printf("-> [%p] %d\n", (void *) current, current->n);
				return (count);
			}
		}

		printf("[%p] %d\n", (void *) current, current->n);

		if (count == 1024)
		{
			printf("-> [%p] %d\n", (void *) current, current->n);
			return (count);
		}

		array[count] = current;
		count++;
		current = current->next;
	}

	return (count);
}
