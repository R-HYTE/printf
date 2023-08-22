#include "main.h"

/* A number could be positve or negative value so we split the functions into two*/

/**
 * print_number - prints a number send to this function
 * @args: List of arguments
 * Return: number of charaters that will end up in the stdout
 */
int print_number(va_list args)
{
	int n;
	int divisor;
	int char_count;
	unsigned int num;

	n  = va_arg(args, int);
	divisor = 1;
	char_count = 0;

	if (n < 0)
	{
		char_count += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	while ((num / divisor) > 9)
		divisor *= 10;

	while (divisor != 0)
	{
		char_count += _putchar(48 + num / divisor);
		num %= divisor;
		divisor /= 10;
	}

	return (char_count);
}

/**
 * print_unsigned_number - function that prints an unsigned number
 * @n: unsigned integer to be printed
 * Return: The amount of numbers printed
 */

int print_unsigned_number(unsigned int n)
{
	int divisor;
	int char_count;
	unsigned int num;

	divisor = 1;
	char_count = 0;

	num = n;

	for (; num / divisor > 9; )
		divisor *= 10;

	while (divisor != 0)
	{
		char_count += _putchar(48 + num / divisor);
		num %= divisor;
		divisor /= 10;
	}

	return (char_count);
}
