#include "main.h"

/**
 * main - prints the program name
 * @argv: an array of pointers to the command-line arguments
 * @argc: The number of command-line arguments
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	if (argc > 0)
	{
		printf("%s\n", argv[0]);
	}
	return (0);
}
