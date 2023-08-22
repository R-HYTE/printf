#include "main.h"
#include <stdio.h>

int hex_det(int, char); /*Prototype for determining which format to use for hexadecimal values*/

/**
 * print_binary - In conjuction with length_of_base function it facilitates 
 * conversion of  a decimal value to a binary digit then reverses this value to be able to print it
 * @args: List of arguments passed
 * Return: length of the number printed
 */
int print_binary(va_list args)
{
	size_t num;
	int i, char_count;
	char *fnum;
	char *rev_str;

	num = va_arg(args, size_t);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	char_count = length_of_base(num, 2);
	fnum = malloc((sizeof(char) * char_count) + 1);
	if (fnum == NULL)
		return (-1); /*if my fnum string is not allocated with bytes then an error will be printed*/

	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
			fnum[i] = '0';
		else
			fnum[i] = '1';
		num = num / 2;
	}
	fnum[i] = '\0';
	rev_str = rev_fnum(fnum);
	if (rev_str == NULL)
		return (-1);
	putchar_base(rev_str);
	free(fnum);
	free(rev_str);
	return (char_count);
}

/**
 * print_octal - Prints the numeric representation of a number in octal base
 * @args: List of all the arguments passed to the program
 * Return: Number of symbols printed to stdout
 */
int print_octal(va_list args)
{
	size_t num;
	int char_count;
	char *fnum, *rev_str;

	num = va_arg(args, size_t);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);

	char_count = length_of_base(num, 8);
	fnum = malloc((sizeof(char) * char_count) + 1);

	if (fnum == NULL)
		return (-1);

	for (char_count = 0; num > 0; char_count++)
	{
		fnum[char_count] = (num % 8) + 48;
		num = num / 8;

	}
	fnum[char_count] = '\0';
	rev_str = rev_fnum(fnum);
	if (rev_str == NULL)
		return (-1);

	putchar_base(rev_str);
	free(fnum);
	free(rev_str);
	return (char_count);
}

/**
 * print_hex_lower - Prints a representation of a decimal number on base16 lowercase
 * @args: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_hex_lower(va_list args)
{
	unsigned int num;
	int char_count;
	int rem_num;
	char *fnum;
	char *rev_hex;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (_putchar('0'));

	if (num < 1)
		return (-1);

	char_count = length_of_base(num, 16);
	fnum = malloc((sizeof(char) * char_count) + 1);
	if (fnum == NULL)
		return (-1);
	for (char_count = 0; num > 0; char_count++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_det(rem_num, 'x');
			fnum[char_count] = rem_num;
		}
		else
			fnum[char_count] = rem_num + 48;
		num = num / 16;
	}
	fnum[char_count] = '\0';
	rev_hex = rev_fnum(fnum);
	if (rev_hex == NULL)
		return (-1);
	putchar_base(rev_hex);
	free(fnum);
	free(rev_hex);
	return (char_count);
}


/**
 * print_hex_upper - Prints a representation of a decimal number on base16 Uppercase
 * @args: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_hex_upper(va_list args)
{
	size_t num;
	int char_count;
	int rem_num;
	char *fnum;
	char *rev_hex;

	num = va_arg(args, size_t);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	char_count = length_of_base(num, 16);
	fnum = malloc((sizeof(char) * char_count) + 1);
	if (fnum == NULL)
		return (-1);
	for (char_count = 0; num > 0; char_count++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_det(rem_num, 'X');
			fnum[char_count] = rem_num;
		}
		else
			fnum[char_count] = rem_num + 48;
		num = num / 16;
	}
	fnum[char_count] = '\0';
	rev_hex = rev_fnum(fnum);
	if (rev_hex == NULL)
		return (-1);

	putchar_base(rev_hex);
	free(fnum);
	free(rev_hex);
	return (char_count);
}

/**
 * hex_det - Checks which hex function is calling it
 * @num: Number to convert into letter
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */
int hex_det(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}
