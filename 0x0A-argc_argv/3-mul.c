#include "main.h"
/**
 * main - multiplies two numbers given as command line arguments
 * @argc: the number of command line arguments
 * @argv: an array of pointers to the command line arguments
 *
 * Return: 0 on success, 1 on error
 */

int main(int argc, char *argv[])
{
	int num1, num2;

/* Verify that two command line arguments were given */

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
/* Convert command line arguments to integers */

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

/* Multiply the two numbers and print the result */

	printf("%d\n", num1 * num2);

	return (0);
}
