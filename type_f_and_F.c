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
			handling_float(x, 15, 52, list->presicion);
			list->widthofline -= ft_len_of_int(x) + list->presicion + 1;
			list->widthofcontent -= ft_len_of_int(x) + list->presicion + 1;
		}
		ft_putchar(' ');
		list->widthofline--;
	}
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
	handling_float(x, 15, 52, list->presicion);

}

void	type_f_and_F(t_printf *list, double x)
{
	if (list->width > ft_len_of_int(x) + list->presicion + 1)
		list->widthofline = list->width;
	else
		list->widthofline = ft_len_of_int(x) + list->presicion + 1;
	list->widthofcontent = ft_len_of_int(x) + list->presicion + 1;
	if (list->flag == '+' && x >= 0)
		list->widthofcontent++;
	if ((list->flag == '-') && (list->width > list->widthofcontent))
		fF_print_with_minus(list, x);
	else
		fF_print_without_minus(list, x);
}
