/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:02:52 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/19 19:07:48 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

void	d_and_i(char *format, ...)
{
	va_list	ap;
	va_start(ap, format);
	int	x;

	x = va_arg(ap, int);
	ft_putnbr(x);
}