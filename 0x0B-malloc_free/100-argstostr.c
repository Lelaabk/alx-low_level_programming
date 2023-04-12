#include <stdlib.h>
#include "main.h"

/**
 * argstostr - main entry
 * @ac: int input
 * @av: double pointer array
 * Return: 0
 */

char *argstostr(int ac, char **av)
{
	int i, j, res = 0, k = 0;
	char *str;

	if (ac == 0 || av == 0)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			k++;
	}
	k += ac;

	str = malloc(sizeof(char) * k + 1);
	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			str[res] = av[i][j];
			res++;
		}
		if (str[res] == '\0')
			str[res++] = '\n';
	}
	return (str);
}
