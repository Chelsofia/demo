#include "shell.h"

/**
 * _myhistory - Shows the history list, one comnd by line, preceded
 *              with line nmbrs, starting at 0.
 * @info: Structure holding potential arguments. Used to manage
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - Puts alias to a string
 * @info: parameter struct
 * @str: The Alias of a string
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int vet;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	vet = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (vet);
}

/**
 * set_alias - Puts alias to string
 * @info: parameter struct
 * @str: The Alias of a string
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - produce an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - imitates the alias builtin (man alias)
 * @info: Structure holding potential arguments. Used to manage
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int h = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (h = 1; info->argv[h]; h++)
	{
		p = _strchr(info->argv[h], '=');
		if (p)
			set_alias(info, info->argv[h]);
		else
			print_alias(node_starts_with(info->alias, info->argv[h], '='));
	}

	return (0);
}
