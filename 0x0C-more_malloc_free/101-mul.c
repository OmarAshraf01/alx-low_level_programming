#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define ERROR_MSG "Error"

/**
 * is_digit - checks if a string contains only digits
 * @s: string to be evaluated
 *
 * Return: 1 if s contains only digits, 0 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}

	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string to be evaluated
 *
 * Return: length of s
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * print_error - prints the error message and exits
 */
void print_error(void)
{
	printf("%s\n", ERROR_MSG);
	exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, len, i, carry, digit1, digit2, *result, a = 0;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		print_error();
	}

	s1 = argv[1];
	s2 = argv[2];
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);

	if (!result)
	{
		return (1);
	}

	for (i = 0; i <= len1 + len2; i++)
	{
		result[i] = 0;
	}

	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		digit1 = s1[len1] - '0';
		carry = 0;

		for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
		{
			digit2 = s2[len2] - '0';
			carry += result[len1 + len2 + 1] + (digit1 * digit2);
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}

		if (carry > 0)
		{
			result[len1 + len2 + 1] += carry;
		}
	}

	for (i = 0; i < len - 1; i++)
	{
		if (result[i])
		{
			a = 1;
		}

		if (a)
		{
			putchar(result[i] + '0');
		}
	}

	if (!a)
	{
		putchar('0');
	}

	putchar('\n');
	free(result);

	return (0);
}
