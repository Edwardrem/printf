#include "main.h"

/**
 * is_printable - check if a character is printable.
 * The function can be used to filter out non-printable
 * characters from a string, or to print only
 * the printable characters in a string.
 * @c: Char to be evaluated.
 * Return: returns 1 if the character c is printable and 0 if it is not.
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - appends the hexadecimal code
 * for the given ASCII code to the buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: returns the number of characters
 * that were appended to the buffer, which is always 3.
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - converts a number to a different size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 * Return: If the size is not S_LONG or S_SHORT,
 * then the number is converted to an int and returned
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - converts an unsigned long int to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 * Return: If the size is S_SHORT, return the number as an unsigned short.
 * Otherwise, return the number as an unsigned int.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
