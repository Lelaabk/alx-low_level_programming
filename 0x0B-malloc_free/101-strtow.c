#include <stdlib.h>
#include "main.h"

/**
 * count - helper function to count the number of words in a string
 *@s: string to evaluate
 *
 * Return: number of words
 */
int count(char *s)
{
	int flag = 0, i = 0, w;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}

	}
	return (w);
}


/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int i, j = 0, len = 0, w, c = 0, start, end;

	while (*(str + len))
		len++;
	w = count(str);
	if (w == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (w + 1));

	if (matrix == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				tmp = (char *)malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[j] = tmp - c;
				j++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}
	matrix[j] = NULL;
	return (NULL);
}
