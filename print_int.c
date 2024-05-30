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
	long int num = va_arg(ptr, int);
	long int mun = num;
	long int i = 0, t = 0, sum = 0;
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
	for (i = 1; mun != 0; i++)
	{
		t++;
		mun = mun / 10;
	}
	str = malloc(sizeof(char) * t);
	if (str == NULL)
		return (-1);
	t--;
	for (; t >= 0; t--)
	{
		str[t] = (num % 10) + 48;
		num = num / 10;
	}
	while (t < i)
	{
		sum += write(1, str[t], 1);
		t++;
	}
	free(str);
	return (sum);
}
