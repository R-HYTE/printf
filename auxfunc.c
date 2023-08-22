#include "main.h"
#include <stdio.h>

/**
 * rev_fnum - reverses a string in place
 * @fnum: string to reverse
 * Return: A pointer to a character
 */
char *rev_fnum(char *fnum)
{
	int i, head;
	char tmp, *dest;

	i = 0;
	while (fnum[i] != '\0')
		i++;

	dest = malloc((sizeof(char) * i) + 1);
	if (dest == NULL)
		return (NULL);

	_memcpy(dest, fnum, i);
	for (head = 0; head < i; head++, i--)
	{
		tmp = dest[i - 1];
		dest[i - 1] = dest[head];
		dest[head] = tmp;
	}
	return (dest);
}

/**
 * putchar_base - calls a putchar function,
 * sends characters to be written on standard output
 * putchar_base - calls a putchar function and sends characters to be written on standard output
 * @fnum: String holding the final number to parse
 */
void putchar_base(char *fnum)
{
	int i;

	for (i = 0; fnum[i] != '\0'; i++)
		_putchar(fnum[i]);
}

/**
 * length_of_base - Calculates and returns the length
 * of a converted value to preferred base
 * @num: The number for which the length is being calculated
 * @base: Base value dealing with
 * Return: An integer representing the length of a number
 */
unsigned int length_of_base(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
		num = num / base;

	return (i);
}

/**
 * _memcpy - copy memory area
 * @dest: Destination for copying
 * @src: Source to copy from
 * @b: The number of bytes to copy
 * Return: The _memcpy() function returns a pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int b)
{
	unsigned int i;

	for (i = 0; i < b; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
