#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * create_file - Creates a file with the specified text content.
 *
 * @filename: The name of the file to create.
 * @text_content: The text content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */

int create_file(const char *filename, char *text_content)
{
	int fd, bytes_written;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	bytes_written = 0;
	while (text_content[bytes_written])
		bytes_written++;

	if (write(fd, text_content, bytes_written) != bytes_written)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
