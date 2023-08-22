#include "main.h"

/**
 * print_reversed - Calls a function to reverse a string then prints the result
 * @args: Argument passed to the function
 * Return: The amount of characters printed
 */
int print_reversed(va_list args)
{
	int i;
	char *str;
	char *ptr;

	str = va_arg(args, char *);
	if (str == NULL)
		return (-1);
	ptr = rev_fnum(str);
	if (ptr == NULL)
		return (-1);
	for (i = 0; ptr[i] != '\0'; i++)
		_putchar(ptr[i]);
	free(ptr);
	return (i);
}

/**
 * rot13 - Replaces a letter with the letter found 13 steps after it in the alphabet sequence
 * @args: string passed into 
 * Return: number of characters converted  in tthe string,
 * an error i.e (-1) if pointer str is NULL
 */
int rot13(va_list args)
{
	int i;
	int j;
	char *str;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char a[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	if (str == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j <= 52; j++)
		{
			if (str[i] == s[j])
			{
				_putchar(a[j]);
				break;
			}
		}
		if (j == 53)
			_putchar(str[i]);
	}
	return (i);
}
