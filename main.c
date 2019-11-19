#include "printf.h"

int		main(void)
{
	char *s = "Hello world!";
	char c = 'Z';
	int	x = -27;


	//printf("wow %c\n", c);
	//ft_printf("test %d\n", 234);
	//ft_printf("hello %s korova\n", s);
	ft_printf("%s %c %i\n", s, c, x);
	return (0);
}
