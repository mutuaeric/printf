#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list args, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

int _char(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int _string(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int _percent(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int _int(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int _binary(va_list args, char buffer[],
	int flags, int width, int  precision, int size);
int _unsigned(va_list args, char buffer[],
	int flags, int width, int precision,int size);
int _octal(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int _hexadecimal(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int _hexa_upper(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int _hexa(va_list args, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

int _non_printable(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int _pointer(va_list args, char buffer[],
	int flags, int width, int precision, int size);

int _flags(const char *format, int *i);
int _width(const char *format, int *i, va_list args);
int _precision(const char *format, int *i, va_list args);
int _size(const char *format, int *i);

int _reverse(va_list args, char buffer[],
	int flags, int width, int precision, int size);

int _rot13string(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/**** UTILS *******/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
