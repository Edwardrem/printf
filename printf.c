#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += print_char(args);
					break;
				case 's':
					count += print_string(args);
					break;
				case '%':
					count += print_percent();
					break;
				default:
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);

	return (count);
}

/**
 * print_char - prints a character
 * @args: argument list
 *
 * Return: the number of characters printed
 */
int print_char(va_list args)
{
	putchar(va_arg(args, int));
	return (1);
}

/**
 * print_string - prints a string
 * @args: argument list
 *
 * Return: the number of characters printed
 */
int print_string(va_list args)
{
	int count = 0;
	char *str = va_arg(args, char *);

	while (*str)
	{
		putchar(*str);
		str++;
		count++;
	}

	return (count);
}

/**
 * print_percent - prints a percent sign
 *
 * Return: the number of characters printed
 */
int print_percent(void)
{
	putchar('%');
	return (1);
}
