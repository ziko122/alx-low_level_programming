#include "main.h"

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
ssize_t total_written = 0, bytes_read, bytes_written;

if (!filename)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

buf = malloc(letters);
if (!buf)
return (0);

while ((bytes_read = read(fd, buf, letters)) > 0)
{
bytes_written = write(STDOUT_FILENO, buf, bytes_read);
if (bytes_written == -1)
{
free(buf);
close(fd);
return (0);
}
total_written += bytes_written;
}
free(buf);
close(fd);
return (total_written);
}

