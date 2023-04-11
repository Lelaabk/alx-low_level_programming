#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - duplicate to new memory space location
 * @str: char
 * Return: 0
 */

char *_strdup(char *str)
{
	char *m;
	int i, r = 0;

	if (str == NULL)
		return (NULL);

	i = 0;
	while (str[i] != '\0')
		i++;

	m = malloc(sizeof(char) * (i + 1));
	if (m == NULL)
		return (NULL);

	for (r = 0; str[r]; r++)
		m[r] = str[r];

	return (m);
}
