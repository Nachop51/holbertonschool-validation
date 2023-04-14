#include "main.h"

/**
 * p_str - print a string
 * @args: argument list
 * @buffer: buffer to write to
 */
void p_str(buffer_t *buffer, va_list args)
{
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";
	write_buffer_str_n(buffer, str, _strlen(str));
}

/**
 * p_char - print a character
 * @args: argument list
 * @buffer: buffer to write to
 */
void p_char(buffer_t *buffer, va_list args)
{
	char c = va_arg(args, int);

	write_buffer(buffer, c);
}

/**
 * p_percent - print a percent sign
 * @args: argument list
 * @buffer: buffer to write to
 */
void p_percent(buffer_t *buffer, va_list args)
{
	(void)args;
	write_buffer(buffer, '%');
}

/**
 * p_int - print an integer
 * @args: argument list
 * @buffer: buffer to write to
 */
void p_int(buffer_t *buffer, va_list args)
{
	long int long_n = 0;

	if (buffer->mod.length & LENGTH_L)
		long_n = va_arg(args, long int);
	else
		long_n = va_arg(args, int);

	format_number(long_n, 10, buffer, LOWER, SIGNED);
}
