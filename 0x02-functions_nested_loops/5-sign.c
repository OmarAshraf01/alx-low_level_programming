#include "main.h"

/**
 * print_sign - prints the sign of a number.
 * @n: integer to be checked.
 *
 * Return: 1 if positive, 0 if zero, -1 if negative.
 */
int print_sign(int n)
{
	int result;

	if (n > 0)
	{
		result = 1;
		_putchar('+');
	}
	else if (n == 0)
	{
		result = 0;
		_putchar('0');
	}
	else
	{
		result = -1;
		_putchar('-');
	}
	return (result);
}

