#include "printf.h"

void	fF_print_with_minus(t_printf *list, double x)
{
	while (list->widthofline > 0)
	{
		while (list->widthofcontent)
		{
			if (list->flag == '+' && (int)x >= 0)
			{
					ft_putchar('+');
					list->widthofline--;
					list->widthofcontent--;
			}
			handling_float(x, 15, 52);
			list->widthofline -= ft_len_of_double(x);
			list->widthofcontent -= ft_len_of_double(x);
		}
		ft_putchar(' ');
		list->widthofline--;
	}
}

void	fF_presicion_over_len(t_printf *list, double x)
{
	if (list->flag == '+' && (int)x >= 0)
	{
		ft_putchar('+');
		list->widthofline--;
		list->widthofcontent--;
	}
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
	handling_float(x, 15, 52);
}

void	fF_print_without_minus(t_printf *list, double x)
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
	if (list->flag == '+' && (int)x >= 0)
	{
		ft_putchar('+');
		list->widthofline--;
		list->widthofcontent--;
	}
	handling_float(x, 15, 52);

}

void	type_f_and_F(t_printf *list, double x)
{
	list->presicion = 6;
	if (list->width > ft_len_of_double(x))
		list->widthofline = list->width;
	else
		if (list->presicion < ft_len_of_double(x) && list->presicion > 0)
			list->widthofline = list->presicion;
		else
		{
			list->widthofline = ft_len_of_double(x);
			if (list->flag == '+' && (int)x >= 0)
				list->widthofline++;
		}
	if (list->presicion < ft_len_of_double(x) - 1)
		list->widthofcontent = ft_len_of_double(x);
	else
		list->widthofcontent = list->presicion;
	if (list->flag == '+' && (int)x >= 0)
		list->widthofcontent++;
	if (list->presicion > ft_len_of_double(x) - 1)
		fF_presicion_over_len(list, x);
	else if ((list->flag == '-') && (list->width > list->widthofcontent))
		fF_print_with_minus(list, x);
	else
		fF_print_without_minus(list, x);
}
