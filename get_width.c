#include "main.h"

/**
 * get_width - get the width of a formatted string.
 * The function can be used to print strings, numbers,
 * and other types of data in a formatted way.
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: variable-length of argument list
 *
 * Return: width of the formatted string.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
