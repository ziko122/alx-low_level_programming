#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read text file and print to STDOUT.
 * @filename: The name of the text file to be read.
 * @letters: The number of letters to be read.
 * Return: The actual number of bytes read and printed.
 *         0 when the function fails or if filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
char *buf;
ssize_t bytes_read, bytes_written, total_written = 0;
if (filename == NULL)
	return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
	return (0);

buf = malloc(sizeof(char) * letters);
if (buf == NULL)
{
	close(fd);
	return (0);
}

bytes_read = read(fd, buf, letters);
if (bytes_read == -1)
{
	free(buf);
	close(fd);
	return (0);
}

while (bytes_read > 0)
{
bytes_written = write(STDOUT_FILENO, buf + total_written, bytes_read);
if (bytes_written == -1)
{
free(buf);
close(fd);
return (0);
}
total_written += bytes_written;
bytes_read -= bytes_written;
}

free(buf);
close(fd);
return (total_written);
}

