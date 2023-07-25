#include "main.h"

/**
 * get_precision - gets the precision of a formatted string
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: variable-length argument list
 *
 * Return: precision of the formatted string.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int precision = -1;

	if (format[*i] == '.')
	{
		*i++;
		if (is_digit(format[*i]))
		{
			precision = 0;
			while (is_digit(format[*i]))
			{
				precision = precision * 10 + (format[*i] - '0');
				*i++;
			}
		}
	}

	return (precision);
}
