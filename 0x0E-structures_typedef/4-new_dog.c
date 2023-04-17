#include <stdlib.h>
#include "dog.h"

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 *           containing a copy of the string given as a parameter.
 * @str: The string to copy.
 *
 * Return: If str == NULL or insufficient memory is available - NULL.
 *         Otherwise - a pointer to the duplicated string.
 */
char *_strdup(char *str)
{
	char *copy;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	copy = malloc(sizeof(char) * (len + 1));

	if (copy == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		copy[i] = str[i];

	copy[i] = '\0';

	return (copy);
}

/**
 * new_dog - Creates a new dog.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - a pointer to the new dog.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *newdog;
	char *newname, *newowner;

	newdog = malloc(sizeof(dog_t));

	if (newdog == NULL)
		return (NULL);

	newname = _strdup(name);
	newowner = _strdup(owner);

	if (newname == NULL || newowner == NULL)
	{
		free(newname);
		free(newowner);
		free(newdog);
		return (NULL);
	}

	newdog->name = newname;
	newdog->age = age;
	newdog->owner = newowner;

	return (newdog);
}
