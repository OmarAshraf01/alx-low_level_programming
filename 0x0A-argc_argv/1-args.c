#include "main.h"

/**
 * main - prints the number of arguments passed into it
 * @argc: number of arguments passed to the program
 * @argv: an array of strings containing the command line arguments
 *
 * Return: 0 on success
 */

int main(int argc,  char **argv)
{
	(void) argv; /*Ignore argv*/

	printf("%d\n", argc - 1);

	return (0);
}
