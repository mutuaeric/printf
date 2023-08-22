#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - produces output according to a format
 *@format: format.
 * Return: Printed characters.
 */
int _printf(const char *format, ...)
{
	int k, count = 0, char_len = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (k = 0; format && format[k] != '\0'; k++)
	{
		if (format[k] != '%')
		{
			buffer[buff_ind++] = format[k];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			char_len++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = _flags(format, &k);
			width = _width(format, &k, args);
			precision = _precision(format, &k, args);
			size = _size(format, &k);
			++k;
			count = handle_print(format, &k, args, buffer,
				flags, width, precision, size);
			if (count == -1)
				return (-1);
			char_len += count;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(args);

	return (char_len);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
