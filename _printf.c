#include "main.h"

/**
 * _printf - Called in the main function
 * and accepts the arguments passed into it
 * @...: Parameters
 * @format: A string containing all the desired characters
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int char_count;
	spec func[] = {
		{"c", print_char},
		{"s", print_fnum},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"r", print_reversed},
		{"R", rot13},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hex_lower},
		{"X", print_hex_upper},
		{NULL, NULL}
	};
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	char_count = analyse(format, func, args);
	va_end(args);
	return (char_count);
}
