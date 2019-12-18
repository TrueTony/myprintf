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
	size_t		base;
	int			cow;
}				t_printf;

int				ft_printf(char *format, ...);
t_printf		*newlist_with_printf();
char			*flag(char *format, t_printf *list);
char			*width(char *format, t_printf *list);
char			*presicion(char *format, t_printf *list);
char			*length(char *format, t_printf *list);
char			*type(char *format, t_printf *list);
void			type_c(t_printf *list, unsigned int c);
void			c_width(t_printf *list, unsigned int c);
void			c_width_minus(t_printf *list, unsigned int c);
void			str(t_printf *list, char *str);
void			str_print_with_minus(t_printf *list, char *str);
void			str_print_without_minus(t_printf *list, char *str);
void			d_and_i(t_printf *list, long long x);
size_t			ft_len_of_int(long long i);
void			di_print_without_minus(t_printf *list, long long x);
void			di_print_with_minus(t_printf *list, long long x);
void			presicion_over_len(t_printf *list, long long x);

void			type_u(t_printf *list, long long x);
void			u_print_without_minus(t_printf *list, long long x);
void			u_presicion_over_len(t_printf *list, long long x);
void			u_print_with_minus(t_printf *list, long long x);
void			type_x_and_X(t_printf *list, long long x);
void			x_print_without_minus(t_printf *list, long long x);
void			x_presicion_over_len(t_printf *list, long long x);
void			x_print_with_minus(t_printf *list, long long x);

char			*adv_ft_itoa(long long n, int base, char c);
size_t			lennum_base(long long n, int base);
void			type_f_and_F(t_printf *list, double x);
int				handling_float(double d, int countofel, int pow, int p, t_printf *list);
char			*nole(void);
void			ft_putchar_cow(char c, t_printf *list);

#endif
