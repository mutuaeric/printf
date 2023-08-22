#include "main.h"

/*********** CHAR ***********/

/**
 * _char - Outputs a character
 * @args: Arguments list
 * @buffer: Buffer array
 * @flags: active flags
 * @width: Width
 * @precision: Precision spec
 * @size: Size
 * Return:  charrs
 */
int _char(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(args, int);

	return (write_char(c, buffer, flags, width, precision, size));
}
/*********** STRING ***************/
/**
 * _string - string output
 * @args: List of args
 * @buffer: Buffer array
 * @flags: ctive flags
 * @width: width.
 * @precision: Precision specific
 * @size: Size specif
 * Return: Number  printed
 */
int _string(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/********** % ************/
/**
 * _percent - a percent sign output
 * @args: List args
 * @buffer: Buffer array
 * @flags:  active flag
 * @width: width.
 * @precision: Preci specif
 * @size: Size specifier
 * Return: characs printed
 */
int _percent(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************ INT ***************/
/**
 * _int - outpu t int
 * @args: arguments list
 * @buffer: Buffer array
 * @flags:  active flags
 * @width: get width.
 * @precision: Precision spec
 * @size: Size
 * Return: printed cacs
 */
int _int(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(args, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/********** BINARY NUM ****************/
/**
 * _binary - prints binary
 * @args: args lsts
 * @buffer: Buffer array
 * @flags:  Calc active flas
 * @width: get wid
 * @precision: Precision specific
 * @size: Size
 * Return: printed char printed.
 */
int _binary(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(args, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
