#include "printf.h"

void	x_print_with_minus(t_printf *list, long long x)
{
	while (list->widthofline > 0)
	{
		while (list->widthofcontent)
		{
			ft_putstr(adv_ft_itoa(x, list->base, list->type));
			list->widthofline -= lennum_base(x, list->base);
			list->widthofcontent -= lennum_base(x, list->base);
		}
		ft_putchar(' ');
		list->widthofline--;
	}
}

void	x_presicion_over_len(t_printf *list, long long x)
{
	if ((int)x < 0)
	{
		ft_putchar('-');
		x *= -1;
		list->widthofline--;
	}
	while (list->widthofcontent > list->widthofline)
	{
		ft_putchar('0');
		list->widthofcontent--;
	}
	ft_putstr(adv_ft_itoa(x, list->base, list->type));
}

void	x_print_without_minus(t_printf *list, long long x)
{
	while (list->widthofline > list->widthofcontent)
	{
		if (list->flag == '0')
		{
			if ((int)x < 0)
			{
				ft_putchar('-');
				x *= -1;
				list->widthofcontent--;
				list->widthofline--;
			}
			ft_putchar('0');
		}
		else
			ft_putchar(' ');
		list->widthofline--;
	}
	ft_putstr(adv_ft_itoa(x, list->base, list->type));

}

void	type_x_and_X(t_printf *list, long long x)
{
	if (list->width > lennum_base(x, list->base))
		list->widthofline = list->width;
	else
	{
		if (list->presicion < lennum_base(x, list->base) && list->presicion > 0)
			list->widthofline = list->presicion;
		else
			list->widthofline = lennum_base(x, list->base);
	}
	if (list->presicion < lennum_base(x, list->base) - 1)
		list->widthofcontent = lennum_base(x, list->base);
	else
		list->widthofcontent = list->presicion;
	if (list->presicion > lennum_base(x, list->base) - 1)
		x_presicion_over_len(list, x);
	else if ((list->flag == '-') && (list->width > list->widthofcontent))
		x_print_with_minus(list, x);
	else
		x_print_without_minus(list, x);
}
