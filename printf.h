#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

# include <stdio.h>

typedef	struct 	s_printf
{
	char		flag;
	size_t		width;
	size_t		presicion;
	char		*length;
	char		type;
	size_t		widthofline;
	size_t		widthofcontent;
	//void	arg; (?)
}				t_printf;

void			ft_printf(char *format, ...);
t_printf		*newlist_with_printf();
char			*flag(char *format, t_printf *list);
char			*width(char *format, t_printf *list);
char			*presicion(char *format, t_printf *list);
char			*length(char *format, t_printf *list);
char			*type(char *format, t_printf *list);
void			c(t_printf *list, unsigned int c);
void			c_width(t_printf *list, unsigned int c);
void			c_width_minus(t_printf *list, unsigned int c);
void			str(t_printf *list, char *str);
void			str_print_with_minus(t_printf *list, char *str);
void			str_print_without_minus(t_printf *list, char *str);
void			d_and_i(t_printf *list, long long x);
size_t			ft_len_of_int(long long i);

#endif
