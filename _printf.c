#include <stdarg.h>
#include <unistd.h>
int print_char(va_list ptr);
int print_str(va_list ptr);
int print_p(va_list ptr);
/**
 * _printf - print to stdout
 * @format: format conversion specifiers
 */
int _printf(const char *format, ...)
{
	unsigned int n, sum = 0, o;
	va_list ptr;
	char arr[] = {'c', 's', '%'};

	int (*fptr[])(va_list ptr) = {print_char, print_str, print_p};
	va_start(ptr, format);
	if (format == NULL)
		return (0);
	for (n = 0; format[n] != '\0'; n++)
	{
		if (format[n] == '%')
		{
			n++;
			for (o = 0; o < 3; o++)
			{
				if (format[n] == arr[o])
				{
					sum += (*fptr[o])(ptr);
				}
			}
		}
		else
		{
			sum += write(1, &format[n], 1);
		}
	}
	va_end(ptr);
	return (sum);
}
/**
 * print_char - prints a char
 * @ptr: va_arg pointer
 */
int print_char(va_list ptr)
{
	char c = (char)va_arg(ptr, int);

	return (write(1, &c, 1));
}
/**
 * print_p - prints % to stdout
 * @ptr: va_arg pointer
 */
int print_p (va_list ptr__attribute__((unused)))
{
	return (write(1, "%", 1));
}
/**
 * print_str - print string to stdout
 * @ptr: va_arg pointer
 */
int print_str(va_list ptr)
{
	unsigned int i = 0;
	char *str = va_arg(ptr, char*);

	while (str[i])
	{
		i++;
	}
	return (write(1, str, i));
}
