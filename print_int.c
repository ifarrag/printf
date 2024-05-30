#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * print_int - print integer with %d an %i
 * @ptr: va_arg pointer
 * Return: sum of chars that printed
 */
int print_int(va_list ptr)
{
	int num = va_arg(ptr, int);
	int mun = num;
	int i = 0, t = 0, sum = 0;
	char *str;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (mun < 0)
	{
		sum++;
		mun = mun * -1;
		num = num * -1;
		write(1, "-", 1);
	}
	for (i = 0; mun != 0; i++)
	{
		t++;
		mun = mun / 10;
	}
	str = malloc(sizeof(char) * (t + 1));
	if (str == NULL)
		return (-1);
	str[t] = '\0';
	for (--t; t >= 0; t--)
	{
		str[t] = (num % 10) + 48;
	}
	sum = write(1, str, t);
	free(str);
	return (sum);
}
