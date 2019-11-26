#include "printf.h"

int		main(void)
{
	//char c = 'Z';
	//char c2 = 'Z';
	int	x = -27;
	//char *str = "hello, world";
/*
	printf(":%c:\n", c);
	printf(":%3c:\n", c);
	printf(":%-3c:\n", c);

	printf("\n");

	ft_printf(":%c:\n", c);
	ft_printf(":%3c:\n", c);
	ft_printf(":%-3c:\n", c);

	printf("\n");

	printf(":%s:\n", str);
	printf(":%10s:\n", str);
	printf(":%.10s:\n", str);
	printf(":%-10s:\n", str);
	printf(":%.15s:\n", str);
	printf(":%15s:\n", str);
	printf(":%-15s:\n", str);
	printf(":%15.10s:\n", str);
	printf(":%-15.10s:\n", str);
	printf(":%-12.20s:\n", str);

	printf("\n");

	ft_printf(":%s:\n", str);
	ft_printf(":%10s:\n", str);
	ft_printf(":%.10s:\n", str);
	ft_printf(":%-10s:\n", str);
	ft_printf(":%.15s:\n", str);
	ft_printf(":%15s:\n", str);
	ft_printf(":%-15s:\n", str);
	ft_printf(":%15.10s:\n", str);
	ft_printf(":%-15.10s:\n", str);
	ft_printf(":%-12.20s:\n", str);
*/

	printf(":%d:\n", x);
	printf(":%5d:\n", x);
	printf(":%+d:\n", x);
	printf(":%+5d:\n", x);
	printf(":%-5d:\n", x);
	printf(":%05d:\n", x);

	printf("\n");
	ft_printf(":%d:\n", x);
	ft_printf(":%5d:\n", x);
	ft_printf(":%+d:\n", x);
	ft_printf(":%+5d:\n", x);
	ft_printf(":%-5d:\n", x);
	ft_printf(":%05d:\n", x);

	//ft_printf("wow eto c=%c, a eto c2=%c\n", c, c2);
	return (0);
}
