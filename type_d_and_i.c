#include "printf.h"

size_t	ft_len_of_int(long long i)
{
	size_t	res;

	res = 1;
	if ((int)i < 0)
		res++;
	while (i > 10)
	{
		res++;
		i /=10;
	}
	return (res);
}

void	di_print_with_minus(t_printf *list, long long x)
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
			ft_putstr(ft_itoa(x));
			list->widthofline -= ft_len_of_int(x);
			list->widthofcontent -= ft_len_of_int(x);
		}
		ft_putchar(' ');
		list->widthofline--;
	}
}

void	di_print_without_minus(t_printf *list, long long x)
{
	//printf("%I64i\n", list->widthofline);
	//printf("%I64i\n", list->widthofcontent);
	while (list->widthofline > 0)
	{
		while (list->widthofline > list->widthofcontent)
		{
			if (list->flag == '0')
				ft_putchar('0');
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
		ft_putstr(ft_itoa(x));
		list->widthofline -= ft_len_of_int(x);
		list->widthofcontent -= ft_len_of_int(x);
	}
}

void	d_and_i(t_printf *list, long long x)
{
	if (list->width > ft_len_of_int(x))
		list->widthofline = list->width;
	else
		if (list->presicion < ft_len_of_int(x) && list->presicion > 0)
			list->widthofline = list->presicion;
		else
		{
			list->widthofline = ft_len_of_int(x);
			if (list->flag == '+' && (int)x >= 0)
				list->widthofline++;
		}
	if (list->presicion < ft_len_of_int(x) && list->presicion > 0)
		list->widthofcontent = list->presicion;
	else
		list->widthofcontent = ft_len_of_int(x);
	if (list->flag == '+' && (int)x >= 0)
		list->widthofcontent++;
	if ((list->flag == '-') && (list->width > list->widthofcontent))
		di_print_with_minus(list, x);
	else
		di_print_without_minus(list, x);
	//printf("%li\n", x);

}
