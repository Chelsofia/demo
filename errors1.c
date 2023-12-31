#include "shell.h"

/**
 * _erratoi - converts Strng to  Integer
 * @s: the strng that is converted
 * Return: 0 if no numbers in string, cnvrtd nmbr otherwise
 *       -1 on error
 */
int _erratoi(char *s)
{
	int h = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (h = 0;  s[h] != '\0'; h++)
	{
		if (s[h] >= '0' && s[h] <= '9')
		{
			result *= 10;
			result += (s[h] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - Gives an error message
 * @info: the Paramtr & Rtrn info struct
 * @estr: string holding specified error type
 * Return: 0 if no nmbrs in strng, cnvrtd nmbr otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - Functn prints a decimal(intgr) nmbr (base 10)
 * @input: The input
 * @fd: The filedescriptor written to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int h, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (h = 1000000000; h > 1; h /= 10)
	{
		if (_abs_ / h)
		{
			__putchar('0' + current / h);
			count++;
		}
		current %= h;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - Cnvrtr function, a copy of itoa
 * @num: nmbr
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - Funct substitute first instance of '#' with '\0'
 * @buf: address of the string to alter
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int h;

	for (h = 0; buf[h] != '\0'; h++)
		if (buf[h] == '#' && (!h || buf[h - 1] == ' '))
		{
			buf[h] = '\0';
			break;
		}
}
