#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string of 0 and 1 characters.
 *
 * Return: The converted number, or 0 if there is one or more
 *         characters in the string b that is not 0 or 1.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int i;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] == '0' || b[i] == '1')
			num = (num * 2) + (b[i] - '0');
		else
			return (0);
	}

	return (num);
}
