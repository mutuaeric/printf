#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Input format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	char buffer[1024]; /* Local buffer */
	int buffer_index = 0; /* Index for buffer */

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			buffer[buffer_index++] = *format;
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				buffer[buffer_index++] = *format;
				count++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);
				buffer[buffer_index++] = c;
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
				{
					buffer[buffer_index++] = str[str_len];
					str_len++;
				}
				count += str_len;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int d = va_arg(args, int);
				char num_buffer[20]; /* Adjust size as needed */
				int int_len = snprintf(num_buffer, sizeof(num_buffer), "%d", d);
				int i;

				for (i = 0; i < int_len; i++)
					buffer[buffer_index++] = num_buffer[i];

				count += int_len;
			}
			else if (*format == 'b') /* Handling 'b' specifier */
			{
				unsigned int num = va_arg(args, unsigned int);
				char bin_str[33]; /* Binary representation 32 bits + null */
				int i, bin_len;

				for (i = 31; i >= 0; i--)
				{
					bin_str[31 - i] = (num & (1 << i)) ? '1' : '0';
				}
				bin_str[32] = '\0';
				bin_len = 32;

				for (i = 0; i < bin_len; i++)
					buffer[buffer_index++] = bin_str[i];

				count += bin_len;
			}
		}

		/* Check if the buffer is full */
		if ((unsigned int)buffer_index >= sizeof(buffer))
		{
			write(1, buffer, buffer_index);
			buffer_index = 0; /* Reset buffer index */
		}

		format++;
	}

	/* Output remaining content in the buffer */
	if (buffer_index > 0)
		write(1, buffer, buffer_index);

	va_end(args);
	return (count);
}
