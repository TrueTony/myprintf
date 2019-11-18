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
void	find_flags(char *str)
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

	while (*format)
	{
		ft_putchar(*format);

		if (*format == '%')
		{
			format++;
			if (*format == 'd')
			{
				x = va_arg(ap, int);
				ft_putnbr(x);
			}
			if (*format == 's')
			{
				s = va_arg(ap, char*);
				ft_putstr(s);
			}

		}

		format++;
	}
	va_end (ap);
}
