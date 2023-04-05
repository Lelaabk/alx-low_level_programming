#include "main.h"
/**
 * _strlen_recursion - Prints the length of a string.
 * @s: the string to be printed
 * Return: the length of string
 */
int _strlen_recursion(char *s)
{
	if (s[0] != '\0')
		return (1 + _strlen_recursion(s + 1));
	return (0);
}

/**
 * pal_isTrue - check if str is palindrome.
 * @str: string base address.
 * @x: left index.
 * @y: rigth index.
 * Return: 1 if str is palindrome, 0 otherwise.
 */
int pal_isTrue(char *str, int x, int y)
{
	if (str[x] == str[y])
		if (x > y / 2)
			return (1);
		else
			return (pal_isTrue(str, x + 1, y - 1));
	else
		return (0);
}

/**
 * is_palindrome - check if s is palindrome
 * @s: base address for string.
 *
 * Return: 1 if n is prime, 0 otherwise.
 */
int is_palindrome(char *s)
{
	return (pal_isTrue(s, 0, _strlen_recursion(s) - 1));
}
