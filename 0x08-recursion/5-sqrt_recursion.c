#include "main.h"

/**
 * calculate_sqrt - calculate the square root of a number recursively
 *
 * @n: the number to calculate the square root of
 * @i: the iterator to check the square of
 *
 * Return: the square root if found, -1 if not
 */

int calculate_sqrt(int n, int i)
{
	if (i * i == n)
	{
		return (i);
	}
	else if (i * i > n)
	{
		return (-1);
	}
	return (calculate_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 *
 * @n: the number to calculate the square root of
 *
 * Return: the square root if found, -1 if not
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (calculate_sqrt(n, 0));
}
