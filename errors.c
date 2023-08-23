#include "shell.h"

/**
 * _eputs - This Prints an input string
 * @str: The printed strng
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int h = 0;

	if (!str)
		return;
	while (str[h] != '\0')
	{
		_eputchar(str[h]);
		h++;
	}
}

/**
 * _eputchar - Notes the char C to stderr
 * @c: The Char to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int h;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || h >= WRITE_BUF_SIZE)
	{
		write(2, buf, h);
		h = 0;
	}
	if (c != BUF_FLUSH)
		buf[h++] = c;
	return (1);
}

/**
 * _putfd - Notes the char C to given fd
 * @c: The Char printed
 * @fd: The filedescriptor written to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int h;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || h >= WRITE_BUF_SIZE)
	{
		write(fd, buf, h);
		h = 0;
	}
	if (c != BUF_FLUSH)
		buf[h++] = c;
	return (1);
}

/**
 * _putsfd - An input string is prntd
 * @str: The string that is printed
 * @fd: the filedescriptor written to
 *
 * Return: the nmbr of chars put
 */
int _putsfd(char *str, int fd)
{
	int h = 0;

	if (!str)
		return (0);
	while (*str)
	{
		h += _putfd(*str++, fd);
	}
	return (h);
}
