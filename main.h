#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
* struct - structure that defines specifier directive and funct
*
* @direct: The directive
* @ptr: pointer to function that passes a variadic list
*/
struct spec_direct
{
	char *direct;
	int (*ptr)(va_list);
};
typedef struct spec_direct spec;

<<<<<<< HEAD

=======
/*Main functions*/
>>>>>>> 43e5d19 (Modifications of existing files)
int analyse(const char *format, spec func[], va_list arg_list);
int _printf(const char *format, ...);
int _putchar(char);
int print_char(va_list);
int print_fnum(va_list);
int print_percent(va_list);
int print_integer(va_list);
int print_number(va_list);
int print_binary(va_list args);
int print_reversed(va_list args);
int rot13(va_list args);
int unsigned_integer(va_list);
int print_octal(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);

unsigned int length_of_base(unsigned int, int);
char *rev_fnum(char *);
void putchar_base(char *fnum);
char *_memcpy(char *dest, char *src, unsigned int b);
int print_unsigned_number(unsigned int);

#endif
