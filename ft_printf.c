/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:45:26 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/18 20:16:23 by ksenaida         ###   ########.fr       */
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
	va_list	ap;
	va_start(ap, format);
	int 	x;
	char	*s;

	x = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				x = va_arg(ap, int);
				ft_putnbr(x);
			}
			if (*format == 'c')
			{
				x = va_arg(ap, int);
				ft_putchar(x);
			}
			if (*format == 's')
			{
				s = va_arg(ap, char*);
				ft_putstr(s);
			}
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end (ap);
}
