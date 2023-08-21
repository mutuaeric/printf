#include "main.h"
/**
 * _printf - produces output according to a format
 * @format:input
 *
 * Return: printed bytes
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	/* if the format is NULL, exit with error message*/
	if (format == NULL)
		return (-1);
	va_start(args, format);

	/*if format is present continue to the loop*/
	while (*format)
	{
		/*if format is not % you print value*/
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else /*if format is % then continue to loop*/
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%') /*if format is %% print %*/
			{
				write(1, format, 1);
				count++;
			}
			else if (*format == 'c')/*if format is %c print characters*/
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')/*if format is %s print string*/
			{
				char *str = va_arg(args, char*);
					int str_len = 0;

				while (str[str_len] != '\0')
				       str_len++;

				write(1, str, str_len);
				count += str_len;
			}
			else if (*format == 'd')/*if format is %d print integer*/
			{
				int d = va_arg(args, int);
					/*int int_len = 0;

				while (d[int_len] != '\0')
					int_len++;*/

				write(1, &d, 1);
				count++;
			}
			else if (*format == 'i')/*if format is %i print long int*/
			{
				long int i = va_arg(args, int);
					/*int l_int_len = 0;

				while (i[l_int_len] != '\0')
					l_int_len++;*/

				write(1, &i, 1);
				count++;
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
