#include "main.h"

/**
 * print_char - prints a char
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	return (write(1, &c, 1));
}
