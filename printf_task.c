#include "main.h"

#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - produces output according to a format
 * @format:input
 *
 * Return: printed bytes
 */
int _printf(const char *format, ...)
{
	int j = 0, k;
	va_list args;
	int count = 0; /* tracks printed characters*/

	va_start(args, format);
	for (j = 0; format[j] != '\0'; j++)
	{
		if (format[j] == '%')
		{
			j++;
			if (format[j] == 'c')
			{
				char ch = va_arg(args, int);

				_putchar (ch);
				count++;
			}
			else if (format[j] == 's')
			{
				char *str = va_arg(args, char *);

				for (int k = 0; str[k] != '\0'; k++)
				{
					_putchar (str[k]);
					count++;
				}
			}
			else if (format[j] == '%')
			{
				_putchar('%');
				count++;
			}
			else
			{
				/*ignore*/
			}
		}
		else
		{
			_putchar (format[j]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
