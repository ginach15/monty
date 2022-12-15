#include "monty.h"

/**
 * isint - checks if a string can be converted to an integer
 * @s: string to be checked
 * Return: 0 if string can be converted to integer, 1 if not
 */

int isint(char *s)

{

	int i = 0;

	if (s[0] == '-')

		i++;

	while (s[i] != '\0')

	{

		if (isdigit(s[i]) == 0)

			return (1);

		i++;

	}

	return (0);

}
