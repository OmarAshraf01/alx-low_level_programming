#include "main.h"

/**
 * is_prime_number - checks if an integer is a prime number
 *
 * @n: integer to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (is_prime(n, n - 1));
}

/**
 * is_prime - recursively checks if a number is prime
 *
 * @n: integer to check
 * @divisor: divisor to check if n is divisible by
 *
 * Return: 1 if n is prime, 0 otherwise
 */

int is_prime(int n, int divisor)
{
	if (divisor == 1)
		return (1);
	if (n % divisor == 0)
		return (0);
	return (is_prime(n, divisor - 1));
}
