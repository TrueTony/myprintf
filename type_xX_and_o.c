#include "printf.h"

void	x_print_with_minus(t_printf *list, long long x)
{
	while (list->widthofline > 0)
	{
		while (list->widthofcontent)
		{
			ft_putstr_cow(adv_ft_itoa(x, list->base, list->type), list);
			list->widthofline -= lennum_base(x, list->base);
			list->widthofcontent -= lennum_base(x, list->base);
		}
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
}

void	x_presicion_over_len(t_printf *list, long long x)
{
	if ((int)x < 0)
	{
		ft_putchar_cow('-', list);
		x *= -1;
		list->widthofline--;
	}
	while (list->widthofcontent > list->widthofline)
	{
		ft_putchar_cow('0', list);
		list->widthofcontent--;
	}
	ft_putstr_cow(adv_ft_itoa(x, list->base, list->type), list);
}

void	x_print_without_minus(t_printf *list, long long x)
{
	while (list->widthofline > list->widthofcontent)
	{
		if (list->flag == '0')
		{
			if ((int)x < 0)
			{
				ft_putchar_cow('-', list);
				x *= -1;
				list->widthofcontent--;
				list->widthofline--;
			}
			ft_putchar_cow('0', list);
		}
		else
			ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	ft_putstr_cow(adv_ft_itoa(x, list->base, list->type), list);
}

void	sharp_u_x(t_printf *list)
{
	if (list->flag == '#' && list->type == 'o')
	{
		ft_putchar_cow('0', list);
		list->widthofline--;
	}
	else if (list->flag == '#' && list->type == 'x')
	{
		ft_putstr_cow("0x", list);
		list->widthofline -= 2;
	}
	else if (list->flag == '#' && list->type == 'X')
	{
		ft_putstr_cow("0X", list);
		list->widthofline -= 2;
	}
}

void	type_x_and_X(t_printf *list, long long x)
{
	if (x == 4294967296)
	{
		ft_putchar_cow('0', list);
		return ;
	}
	if (list->width > lennum_base(x, list->base))
		list->widthofline = list->width;
	else
	{
		if (list->presicion < lennum_base(x, list->base) && list->presicion > 0)
			list->widthofline = list->presicion;
		else
			list->widthofline = lennum_base(x, list->base);
	}
	if (list->presicion < lennum_base(x, list->base))
		list->widthofcontent = lennum_base(x, list->base);
	else
		list->widthofcontent = list->presicion;
	if (list->flag == '#' && x > 0)
		sharp_u_x(list);
	if (list->presicion > lennum_base(x, list->base) - 1)
		x_presicion_over_len(list, x);
	else if ((list->flag == '-') && (list->width > list->widthofcontent))
		x_print_with_minus(list, x);
	else
		x_print_without_minus(list, x);
}
