#include "main.h"

#define BUFFER_SIZE 1024

/**
 * _printf - produces output according to a format
 * @format: input format string
 * @...: additional arguments for format
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

	char buffer[BUFFER_SIZE];
	char *buf_ptr = buffer;
	char *buf_end = buffer + BUFFER_SIZE;

	while (*format)
	{
		if (*format != '%')
		{
			if (buf_ptr < buf_end)
			{
				*buf_ptr++ = *format;
				count++;
			}
			else
			{
				write(1, buffer, BUFFER_SIZE);
				buf_ptr = buffer;
			}
		}
		else
		{
			format++;

			if (*format == '\0')
				break;

			if (*format == '%')
			{
				if (buf_ptr < buf_end)
				{
					*buf_ptr++ = '%';
					count++;
				}
				else
				{
					write(1, buffer, BUFFER_SIZE);
					buf_ptr = buffer;
				}
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);
				if (buf_ptr < buf_end)
				{
					*buf_ptr++ = c;
					count++;
				}
				else
				{
					write(1, buffer, BUFFER_SIZE);
					buf_ptr = buffer;
				}
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				while (*str)
				{
					if (buf_ptr < buf_end)
					{
						*buf_ptr++ = *str;
						count++;
					}
					else
					{
						write(1, buffer, BUFFER_SIZE);
						buf_ptr = buffer;
					}
					str++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				int d = va_arg(args, int);
				buf_ptr += snprintf(buf_ptr, buf_end - buf_ptr, "%d", d);
				count += buf_ptr - buffer;
			}
		}

		format++;
	}

	if (buf_ptr > buffer)
	{
		write(1, buffer, buf_ptr - buffer);
	}

	va_end(args);
	return (count);
}
