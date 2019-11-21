#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

# include <stdio.h>

typedef	struct s_printf
{
	char	flag;
	int		width;
	int		presicion;
	char	*length;
	char	type;
	//void	arg; (?)
}				t_printf;

void		ft_printf(char *format, ...);
t_printf	*newlist_with_printf();
char		*flag(char *format, t_printf *list);
char		*width(char *format, t_printf *list);
char		*presicion(char *format, t_printf *list);
char		*length(char *format, t_printf *list);
char		*type(char *format, t_printf *list);
void		c(t_printf *list, unsigned int c);

#endif
