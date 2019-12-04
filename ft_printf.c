/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:45:26 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/23 15:44:56 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_printf(char *format, ...)
{
	t_printf	*list;
	va_list	ap;
	va_start(ap, format);
	//int				x;
	unsigned	int ux;
	long long		lx;
	//float			fx;
	char			*s;

	//x = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			list = newlist_with_printf();
			format = flag(format, list);
			//printf("%c %I64i %I64i %s %c\n", list->flag, list->width, list->presicion, list->length, list->type);
			if (list->type == 'c')
			{
				ux = va_arg(ap, int);
				type_c(list, ux);
			}

			else if (list->type == 's' || list->type == 'S')
			{
				s = va_arg(ap, char*);
				str(list, s);
			}
			else if (list->type == 'd' || list->type == 'i')
			{
				lx = va_arg(ap, long long);
				d_and_i(list, lx);
			}
			else if (list->type == 'u')
			{
				lx = va_arg(ap, long long);
				type_u(list, lx);
			}
			else if (list->type == 'x' || list->type == 'X' || list->type == 'o')
			{
				lx = va_arg(ap, long long);
				type_x_and_X(list, lx);
			}
		}
		else
			ft_putchar(*format);
		format++;
	}
	//printf("%c %i %i %s %c", list->flag, list->width, list->presicion, list->length, list->type);
	//va_end (ap);
}
