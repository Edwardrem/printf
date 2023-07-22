#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c, buffer[1024], *s, *b = buffer;
	int d, base;
	unsigned int u;

	va_start(args, format);
	for (; *format; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				c = (char)va_arg(args, int), write(1, &c, 1), count++;
			else if (*format == 's')
				s = va_arg(args, char *), count += write(1, s, strlen(s));
			else if (*format == '%')
				write(1, "%", 1), count++;
			else if (*format == 'd' || *format == 'i')
			{
				d = va_arg(args, int);
				if (d < 0)
					d = -d, write(1, "-", 1), count++;
				for (base = 10; d; d /= base)
					*b++ = "0123456789"[d % base];
				while (b-- != buffer)
					write(1, b, 1), count++;
				b = buffer;
			}
			else if (*format == 'u' || *format == 'o' || *format == 'x' || *format == 'X')
			{
				u = va_arg(args, unsigned int);
				base = (*format == 'u') ? 10 : (*format == 'o') ? 8 : 16;
				for (; u; u /= base)
					*b++ = "0123456789abcdef"[u % base];
				while (b-- != buffer)
					write(1, (*format == 'X') ? b - ('a' - 'A') : b, 1), count++;
				b = buffer;
			}
		}
		else
			write(1, format, 1), count++;
	}
	va_end(args);
	return (count);
}
