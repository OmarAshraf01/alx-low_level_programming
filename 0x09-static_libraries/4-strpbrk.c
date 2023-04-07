#include <stddef.h>
#include <string.h>

/**
 * _strpbrk - searches a string for any of a set of bytes.
 * @s: string to search in.
 * @accept: bytes to search for.
 * Return: pointer to the byte in s that matches one of the bytes in accept,
 * or NULL if no such byte is found.
 */
char *_strpbrk(char *s, char *accept)
{
	char *match = NULL;
	char *a;
	char *b;

	for (a = accept; *a; a++)
	{
		b = s;

		while ((b = strchr(b, *a)) != NULL)
		{
			if (match == NULL || b < match)
				match = b;
			b++;
		}
	}
	return (match);
}
