#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to count the words of.
 *
 * Return: The number of words in the string.
 */
static int count_words(char *str)
{
	int count = 0;
	int in_word = 0;

	while (*str)
	{
		if (*str == ' ')
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}

	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: If str is NULL or contains no words - NULL.
 *		 Otherwise - a pointer to an array of strings (words).
 */
char **strtow(char *str)
{
	char **words;
	int count;
	int i = 0;
	int j = 0;
	int k = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	count = count_words(str);
	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);

	while (i < count)
	{
		while (str[j] == ' ')
			j++;

		k = j;
		while (str[k] != ' ' && str[k] != '\0')
			k++;

		words[i] = malloc(sizeof(char) * (k - j + 1));
		if (words[i] == NULL)
		{
			for (i = i - 1; i >= 0; i--)
				free(words[i]);
			free(words);
			return (NULL);
		}

		for (; j < k; j++)
			words[i][j - (k - j)] = str[j];

		words[i][j - (k - j)] = '\0';
		i++;
	}

	words[i] = NULL;
	return (words);
}
