#include "main.h"
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
		} format++;
	va_end(args);
	return (count); }
