#include "main.h"

/**
 * analyse - Based on the string being passed,
 * it parses it and determines functions being called
 * @format: A string
 * @func: All posible functions.
 * @args: argumentents passed into
 * Return: Number of characters printed.
 */
int analyse(const char *format, spec func[], va_list args)
{
	int i, j;
	int value, char_count;

	char_count = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; func[j].direct != NULL; j++)
			{
				if (format[i + 1] == func[j].direct[0])
				{
					value = func[j].ptr(args);
					if (value == -1)
						return (-1);
					char_count += value;
					break;
				}
			}
			if (func[j].direct == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					char_count += 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			char_count++;
		}
	}
	return (char_count);
}
