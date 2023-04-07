#include "main.h"

/**
 * is_digit - checks if a string is composed only of digits
 * @s: the string to check
 *
 * Return: 1 if s is composed only of digits, 0 otherwise
 */
int is_digit(char *s)
{
	if (*s == '-')
		s++;

	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}

	return (1);
}

/**
 * main - entry point
 * @argc: the number of arguments
 * @argv: an array of pointers to the arguments
 *
 * Return: 0 on success, 1 otherwise
 */

int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		if (!is_digit(argv[i]))
		{
			printf("Error\n");
			return (1);
		}

		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);

	return (0);
}
