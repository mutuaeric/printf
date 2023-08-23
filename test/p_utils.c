#include "main.h"

/**
 * print_binary_to_buffer - Converts an unsigned int to binary and adds it to buffer
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
