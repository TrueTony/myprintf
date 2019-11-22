/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:02:52 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/21 19:57:28 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	c(t_printf *list, unsigned int c)
{
	if (list->width > 1)
	{
		if (list->flag == '-')
		{
			ft_putchar(c);
			while (list->width > 2)
			{
				ft_putchar(' ');
				list->width--;
			}
		}
		else if (list->flag == '0')
		{
			while (list->width > 2)
			{
				ft_putchar('0');
				list->width--;
			}
			ft_putchar(c);
		}
		else
		{
			while (list->width > 2)
			{
				ft_putchar(' ');
				list->width--;
			}
			ft_putchar(c);
		}
	}
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
