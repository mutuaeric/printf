#include "main.h"
/*
 * _print_int - print integer
 *@d: integer input
 * @int_len: length of the integer
 */
int _print_int(int d, int int_len)
/**
 * _printf - produces output according to a format
 * @format:input
 * Return: printed bytes
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
       /*if format is NULL exit with an error message*/
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)/*format is present continue to the loop*/
	{
		if (*format != '%')/*If format is not % print the value*/
		{
			write(1, format, 1);
			count++; }
		else /*if format is % then continue to loop*/
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%') /*if format is %% print %*/
			{
				write(1, format, 1);
				count++; }
			else if (*format == 'c')/*if format is %c print characters*/
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				count++; }
			else if (*format == 's')/*if format is %s print string*/
			{
				char *str = va_arg(args, char *);
				int str_len = strlen(str);

				write(1, str, str_len);
				count += str_len; }
			else if (*format == 'd' || *format == 'i')
				_print_int(int d, int int_len);
		} format++; }
	va_end(args);
	return (count);
}

/*
 * _print_int - print integer
 *@d: integer input
 * @int_len: length of the integer
 */

int _print_int(int d, int int_len)
{
	if (*format == 'd' || *format 	== 'i')
	{
		int d = va_arg(args, int);
		char buffer[20];
		int int_len = snprintf(buffer, sizeof(buffer), "%d", d);

		write(1, buffer, int_len);
		count += int_len;
	}
}
