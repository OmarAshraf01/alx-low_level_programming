#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int divisor = 1;
	int bit_position = 63; /* Assumes 64-bit long int */

	while (divisor <= n >> 1)
	{
		divisor <<= 1;
		bit_position--;
	}

	while (divisor)
	{
		if (n & divisor)
			_putchar('1');
		else
			_putchar('0');

		divisor >>= 1;
		bit_position--;
	}
}
