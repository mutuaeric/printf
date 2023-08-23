#include "main.h"

/**
 * print_binary_to_buffer - Converts an unsigned int to binary
 * @buffer: The buffer to store the binary representation
 * @num: The unsigned int to be converted
 *
 * Return: Number of characters added to buffer
 */
int print_binary_to_buffer(char *buffer, unsigned int num)
{
	int count = 0;
	unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
	int leading_zeros = 1;

	while (mask > 0)
	{
		if (num & mask)
		{
			leading_zeros = 0;
			*buffer = '1';
			buffer++;
			count++;
		}
		else if (!leading_zeros)
		{
			*buffer = '0';
			buffer++;
			count++;
		}
		mask >>= 1;
	}

	if (leading_zeros)
	{
		*buffer = '0';
		buffer++;
		count++;
	}

	return (count);
}
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

			if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;

				write(1, str, str_len);
				count += str_len;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int d = va_arg(args, int);
				char buffer[20];
				int int_len = snprintf(buffer, sizeof(buffer), "%d", d);

				write(1, buffer, int_len);
				count += int_len;
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

	va_end(args);
	return (count);
}
