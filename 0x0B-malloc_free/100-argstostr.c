#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: the number of arguments
 * @av: the array of arguments
 *
 * Return: a pointer to the new string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, len = 0, pos = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* compute the length of the new string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
		len++; /* add the length of the newline character */
	}

	/* allocate memory for the new string */
	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);

	/* copy the arguments into the new string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			str[pos++] = av[i][j];
		str[pos++] = '\n';
	}

	/* add the terminating null character */
	str[pos] = '\0';

	return (str);
}
