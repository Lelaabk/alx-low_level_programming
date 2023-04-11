#include <stdlib.h>
#include "main.h"

/**
 * str_concat - get ends of input and add together for size
 * @s1: input one to concat
 * @s2: input two to concat
 * Return: concat of s1 and s2
 */

char *str_concat(char *s1, char *s2)
{
	char *ct;
	int i, x;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	i = x = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[x] != '\0')
		x++;

	ct = malloc(sizeof(char) * (i + x + 1));
	if (ct == NULL)
		return (NULL);

	i = x = 0;
	while (s1[i] != '\0')
	{
		ct[i] = s1[i];
		i++;
	}
	while (s2[x] != '\0')
	{
		ct[i] = s2[x];
		i++;
		x++;
	}
	ct[i] = '\0';
	return (ct);
}
