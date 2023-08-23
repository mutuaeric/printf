#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Input format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;
	char buffer[1024];  /* Local buffer */

	if (format == NULL)
		return (-1);

	va_start(args, format);

	char *buffer_ptr = buffer;
	while (*format)
	{
		if (*format != '%')
		{
			if (count >= 1023)  /* Flush buffer */
			{
				*buffer_ptr = '\0';
				buffer_ptr = buffer;
				write(1, buffer, count);
				buffer_ptr = buffer;
				count = 0;
			}

			*buffer_ptr = *format;
			buffer_ptr++;
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				if (count >= 1023)
				{
					*buffer_ptr = '\0';
					write(1, buffer, count);
					buffer_ptr = buffer;
					count = 0;
				}

				*buffer_ptr = '%';
				buffer_ptr++;
				count++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);
				if (count >= 1023)
				{
					*buffer_ptr = '\0';
					write(1, buffer, count);
					buffer_ptr = buffer;
					count = 0;
				}

				*buffer_ptr = c;
				buffer_ptr++;
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;

				if (count + str_len >= 1023)
				{
					*buffer_ptr = '\0';
					write(1, buffer, count);
					buffer_ptr = buffer;
					count = 0;
				}

				for (i = 0; i < str_len; i++)
				{
					*buffer_ptr = str[i];
					buffer_ptr++;
					count++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				int d = va_arg(args, int);
				char num_buffer[20];
				int int_len = snprintf(num_buffer, sizeof(num_buffer), "%d", d);

				if (count + int_len >= 1023)
				{
					*buffer_ptr = '\0';
					write(1, buffer, count);
					buffer_ptr = buffer;
					count = 0;
				}

				for (i = 0; i < int_len; i++)
				{
					*buffer_ptr = num_buffer[i];
					buffer_ptr++;
					count++;
				}
			}
			else if (*format == 'b')
			{
				unsigned int num = va_arg(args, unsigned int);
				int len = print_binary_to_buffer(buffer_ptr, num);
				buffer_ptr += len;
				count += len;
			}
		}

		format++;
	}

	if (count > 0)
	{
		*buffer_ptr = '\0';
		write(1, buffer, count);
	}

	va_end(args);
	return (count);
}
