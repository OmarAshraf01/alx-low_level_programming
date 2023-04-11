#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all arguments of program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to new string containing all arguments
 */
char *argstostr(int ac, char **av)
{
	int i, j, k, len = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* calculate total length of all arguments */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			len++;
		len++; /* add space for newline character */
	}
	len++; /* add space for null terminator */

	/* allocate memory for new string */
	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);

	/* concatenate all arguments into new string */
	k = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			str[k] = av[i][j];
			k++;
		}
		str[k] = '\n';
		k++;
	}
	str[k] = '\0'; /* add null terminator to end of string */

	return (str);
}
