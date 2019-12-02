/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:02:52 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/23 15:43:07 by ksenaida         ###   ########.fr       */
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
	if (list->flag == '-')
		c_width_minus(list, c);
	else
	{
		while (list->width > 1)
		{
			ft_putchar(' ');
			list->width--;
		}
		ft_putchar(c);
	}
}

void	type_c(t_printf *list, unsigned int c)
{
	if (list->width)
		c_width(list, c);
	else
		ft_putchar(c);
}
