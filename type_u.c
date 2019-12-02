#include "printf.h"

void	u_print_with_minus(t_printf *list, long long x)
{
	//printf("%I64i\n", list->widthofline);
	//printf("%I64i\n", list->widthofcontent);
	while (list->widthofline > 0)
	{
		while (list->widthofcontent)
		{
			ft_putstr(ft_itoa(x));
			list->widthofline -= ft_len_of_int(x);
			list->widthofcontent -= ft_len_of_int(x);
		}
		ft_putchar(' ');
		list->widthofline--;
	}
}

void	u_presicion_over_len(t_printf *list, long long x)
{
	if ((int)x < 0)
	{
		ft_putchar('-');
		x *= -1;
		list->widthofline--;
	}
	//printf("\n%li\n", list->widthofline);
	//printf("%li\n", list->widthofcontent);
	while (list->widthofcontent > list->widthofline)
	{
		ft_putchar('0');
		list->widthofcontent--;
	}
	ft_putstr(ft_itoa(x));
}

void	u_print_without_minus(t_printf *list, long long x)
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
	//printf("%li\n", list->widthofline);
	//printf("%li\n", list->widthofcontent);
	ft_putstr(ft_itoa(x));

}

void	type_u(t_printf *list, long long x)
{
	if ((int)x < 0)
		ft_putstr("4294967269");
	else
	{
		if (list->width > ft_len_of_int(x))
			list->widthofline = list->width;
		else
			if (list->presicion < ft_len_of_int(x) && list->presicion > 0)
				list->widthofline = list->presicion;
			else
				list->widthofline = ft_len_of_int(x);
		if (list->presicion < ft_len_of_int(x) - 1)
			list->widthofcontent = ft_len_of_int(x);
		else
			list->widthofcontent = list->presicion;
		if (list->presicion > ft_len_of_int(x) - 1)
			presicion_over_len(list, x);
		else if ((list->flag == '-') && (list->width > list->widthofcontent))
			di_print_with_minus(list, x);
		else
			di_print_without_minus(list, x);
	}
}
