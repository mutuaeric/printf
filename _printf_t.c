#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: input
 *
 * Return: printed bytes
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
            _putchar(*format);
            count++;
        }
        else
        {
            format++;

            if (*format == '\0')
                break;

            if (*format == '%')
            {
                _putchar('%');
                count++;
            }
            else if (*format == 'c')
            {
                char c = va_arg(args, int);
                _putchar(c);
                count++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char*);
                int str_len = strlen(str);
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
        }
        format++;
    }
    va_end(args);
    return (count);
}
