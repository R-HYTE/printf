#include "main.h"

/**
 * unsigned_integer - Prints Unsigned integers
 * @args: List of all of the argumets
 * Return: a count of the numbers
 */
int unsigned_integer(va_list args)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (print_unsigned_number(num));

	if (num < 1)
		return (-1);
	return (print_unsigned_number(num));
}


/**
 * print_char - function that prints a character
 * @args: parameter passed into funct
 * Return: number of characters printed.
 */
int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}


/**
 * print_fnum - function that prints a string
 * @args: argument based off variable list
 * Return: number of characters printed.
 */
int print_fnum(va_list args)
{
	int i;
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_percent - function that prints a percent symbol
 * @args: argument from my variables list
 * Return: number of characters printed.
 */
int print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}

/**
 * print_integer - function that prints an integer
 * @args: list of arguments pased into the function
 * Return: number of digits a number has
 */
int print_integer(va_list args)
{
	int digit_count;

	digit_count = print_number(args);
	return (digit_count);
}
