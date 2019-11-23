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
/*
void	fork(char *str)
{
	if (*str == 'd')
	{
		int	x;

	}
}
*/



void		ft_printf(char *format, ...)
{
	t_printf	*list;
	va_list	ap;
	va_start(ap, format);
	//int				x;
	unsigned	int ux;
	char			*s;

	//x = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			list = newlist_with_printf();
			//printf("%c %i %i %s %c", list->flag, list->width, list->presicion, list->length, list->type);
			format = flag(format, list);
			if (list->type == 'c')
			{
				ux = va_arg(ap, int);
				c(list, ux);
			}

			if (list->type == 's' || list->type == 'S')
			{
				s = va_arg(ap, char*);
				str(list, s);
			}

/*
			if (*format == 'd' || *format == 'i')
			{
				x = va_arg(ap, int);
				ft_putnbr(x);
			}
			if (*format == 'c')
			{
				ux = va_arg(ap, int);
				ft_putchar(x);
			}
			if (*format == 's')
			{
				s = va_arg(ap, char*);
				ft_putstr(s);
			}
*/
		}
		else
			ft_putchar(*format);
		format++;
	}
	//printf("%c %i %i %s %c", list->flag, list->width, list->presicion, list->length, list->type);
	//va_end (ap);
}
