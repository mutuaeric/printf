#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: input format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;

			if (*format == '\0')
				break;

			if (*format == 'd' || *format == 'i')
			{
				int d = va_arg(args, int);
				char buffer[20];
				int int_len = snprintf(buffer, sizeof(buffer), "%d", d);

				write(1, buffer, int_len);
				count += int_len;
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
