/**
 * _strspn - Gets the length of a prefix substring
 * @s: The string to be searched
 * @accept: The bytes to be searched for
 *
 * Return: The number of bytes in the initial segment of `s` consisting only
 *         of bytes from `accept`
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				break;
		}
		if (accept[j] == '\0')
			return (i);
	}
	return (i);
}

