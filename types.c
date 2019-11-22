/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:02:52 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/22 17:51:23 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	c_width_minus(t_printf *list, unsigned int c)
{
	ft_putchar(c);
	while (list->width > 1)
	{
		ft_putchar(' ');
		list->width--;
	}
}

void	c_width(t_printf *list, unsigned int c)
{
	char tmp;

	tmp = ' ';
	if (list->flag == '-')
		c_width_minus(list, c);
	else
	{
		if (list->flag == '0')
			tmp = '0';
		while (list->width > 1)
		{
			ft_putchar(tmp);
			list->width--;
		}
		ft_putchar(c);
	}
}

void	c(t_printf *list, unsigned int c)
{
	if (list->width)
		c_width(list, c);
	else
		ft_putchar(c);
}

/*
void	d_and_i(char *format, ...)
{
	va_list	ap;
	va_start(ap, format);
	int	x;

	x = va_arg(ap, int);
	ft_putnbr(x);
}
*/
