/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:34:15 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/23 16:28:38 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	str(t_printf *list, char *str)
{
	//printf("!%s\n", str);
	if (list->width > ft_strlen(str))
		list->widthofline = list->width;
	else
		list->widthofline = ft_strlen(str);
	if (list->presicion < ft_strlen(str) && list->presicion > 0)
		list->widthofcontent = list->presicion;
	else
		list->widthofcontent = ft_strlen(str);
	while (list->widthofline)
	{
		if (list->flag == '-')
		{
			while (list->widthofcontent)
			{
				ft_putchar(*str);
				str++;
				list->widthofline--;
				list->widthofcontent--;
			}
			ft_putchar(' ');
			list->widthofline--;
		}
		else
		{
			while (list->widthofline > list->widthofcontent)
			{
				ft_putchar(' ');
				list->widthofline--;
			}
			ft_putchar(*str);
			str++;
			list->widthofline--;
		}
	}
}
