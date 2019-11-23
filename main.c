#include "printf.h"

int		main(void)
{
	//char *s = "Hello world!";
	//char c = 'Z';
	//char c2 = 'Z';
	//int	x = -27;
	char *str = "hello, world";


	//printf("%0*xc\n\n", c);
	//printf("%3c\n", c);
	//printf("%-3c\n", c);
	//ft_printf("%3c\n", c);
	//ft_printf("test %d\n", 234);
	//ft_printf("hello %s korova\n", s);
	//ft_printf("%s %c %i\n", s, c, x);

	//printf("%3.3c\n", c);

	//ft_printf("%-12.5llc");
	//ft_printf("%5casd\n", c);
	//ft_printf("%05casd\n", c);
	//ft_printf("%-5casd\n", c);

	//printf("%#d\n", 123);
	//printf("%#d\n", -123);

/*
	printf(":%s:\n", str);
	printf("%d:%10s:\n", 2, str);
	printf("%d:%.10s:\n", 3, str);
	printf("%d:%-10s:\n", 4, str);
	printf("%d:%.15s:\n", 5, str);
	printf("%d:%15s:\n", 6, str);
	printf("%d:%-15s:\n", 6, str);
	printf("%d:%15.10s:\n", 7, str);
	printf("%d:%-15.10s:\n", 8, str);
	printf("%d:%-12.20s:\n", 10, str);
*/



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
	ft_printf("%d:%-12.20s:\n", 10, str);


	//ft_printf("wow eto c=%c, a eto c2=%c\n", c, c2);
	return (0);
}
