/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_args_of_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:47:52 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/21 21:47:45 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*flag(char *format, t_printf *list)
{
	if (*format == '+')
		list->flag = '+';
	if (*format == '-')
		list->flag  = '-';
	if (*format == '#')
		list->flag  = '#';
	if (*format == '0')
		list->flag  = '0';
	if (*format == ' ')
		list->flag  = ' ';
	if (list->flag != 'Q')
		format++;
	return (width(format, list));
}

char	*width(char *format, t_printf *list)
{
	int	num;

	if (format[0] == '*')
		list->width = -1;
	else
	{
		num = ft_atoi(format);
		list->width = num;
		while (num > 0)
		{
			format++;
			num /= 10;
		}
	}
	return (presicion(format, list));
}

char	*presicion(char *format, t_printf *list)
{
	int num;

	if (*format == '.')
	{
		format++;
		num = ft_atoi(format);
		list->presicion = num;
		while (num > 0)
		{
			format++;
			num /= 10;
		}
		if (*format == '0')
			format++;
	}
	else
		list->np = 'y';
	return (length(format, list));
}

char	*length(char *format, t_printf *list)
{
	if (*format == 'h')
	{
		if (format[1] == 'h')
		{
			list->length = "hh";
			format++;
		}
		else
			list->length = "h";
		format++;
	}
	else if (*format == 'l')
	{
		if (format[1] == 'l')
		{
			list->length = "ll";
			format++;
		}
		else
			list->length = "l";
		format++;
	}
	else if (*format == 'L' || *format == 'z' || *format == 'j' || *format == 't')
	{
		list->length = &format[0];
		format++;
	}
	else
		list->length = NULL;
	return (type(format, list));
}

char	*type(char *format, t_printf *list)
{
	if (format[0] == 'd' || format[0] == 'i' || format[0] == 'u' || format[0] == 'f' || format[0] == 'F' || \
		format[0] == 'e' || format[0] == 'E' || format[0] == 'g' || format[0] == 'G' || format[0] == 'x' || \
		format[0] == 'X' || format[0] == 'o' || format[0] == 's' || format[0] == 'c' || format[0] == 'p' || \
		format[0] == 'a' || format[0] == 'A' || format[0] == 'n')
	{
		list->type = format[0];
	}
	if (format[0] == 'x' || format[0] == 'X')
		list->base = 16;
	if (format[0] == 'o')
		list->base = 8;
	if (list->np == 'y' && (list->type == 'f' || list->type == 'F'))
		list->presicion = 6;
	return (format);
}