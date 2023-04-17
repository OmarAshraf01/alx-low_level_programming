#include "main.h"

/**
 * multiply - multiplies two digits and stores the result in a buffer
 * @num1: first digit
 * @num2: second digit
 * @result: buffer to store the result
 * @offset: offset to start storing the result in the buffer
 */
void multiply(int num1, int num2, char *result, int offset)
{
	int product, carry, i;

	product = num1 * num2;
	carry = product / 10;
	result[offset] = (product % 10) + '0';

	for (i = 1; i <= 2 && carry; i++)
	{
		product = (result[offset - i] - '0') + carry;
		carry = product / 10;
		result[offset - i] = (product % 10) + '0';
	}
}

/**
 * _isdigit - checks if a character is a digit
 * @c: character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: string to check
 *
 * Return: length of s
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s++)
		len++;

	return (len);
}

/**
 * mul - multiplies two positive numbers
 * @num1: first number
 * @num2: second number
 *
 * Return: pointer to the product of num1 and num2
 */
char *mul(char *num1, char *num2)
{
	char *result;
	int len1, len2, i, j, offset;

	if (!num1 || !num2 || !_isdigit(*num1) || !_isdigit(*num2))
		return (NULL);

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	result = malloc(len1 + len2 + 1);

	if (!result)
		return (NULL);

	for (i = 0; i < len1 + len2; i++)
		result[i] = '0';

	for (i = len1 - 1; i >= 0; i--)
	{
		if (num1[i] == '0')
			continue;

		offset = len1 + len2 - i - 1;

		for (j = len2 - 1; j >= 0; j--)
		{
			if (num2[j] == '0')
				continue;

			multiply(num1[i] - '0', num2[j] - '0', result, offset - j);
		}
	}

	for (i = 0; result[i] == '0' && i < len1 + len2 - 1; i++)
		;

	memmove(result, result + i, len1 + len2 - i);
	result[len1 + len2 - i] = '\0';

	return (result);
}

