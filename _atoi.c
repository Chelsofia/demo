#include "shell.h"

/**
 * interactive - If shell is in interactive mode it returns true
 * @info: The struct address
 *
 * Return:In  interactiv mode, its 1 and 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: The Chrctr to check
 * @delim: The Delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checking for alphabetic chrctr
 * @c: The Chrctr to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Changes a strng to an Integr
 * @s: The strng to be chngd
 * Return: 0 if no nmbrs in strng, chngd nmbr otherwise
 */

int _atoi(char *s)
{
	int h, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (h = 0; s[h] != '\0' && flag != 2; h++)
	{
		if (s[h] == '-')
			sign *= -1;

		if (s[h] >= '0' && s[h] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[h] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
