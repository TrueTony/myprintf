#include "printf.h"

int ft_printf(const char *format, ...)
{
	char	*c;
	while (*c)
	{
		while (*c != '%')
		{
			ft_putchar(*c);
		}
		if (*c == '%')
			break ;
		c++;
	}

	return (0);
}
