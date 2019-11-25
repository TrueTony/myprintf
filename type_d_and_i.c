#include "printf.h"

int		ft_len_of_int(int i)
{
	int		res;

	res = 1;
	while (i > 10)
	{
		res++;
		i /=10;
	}
	return (res);
}

void	d_and_i(t_printf *list, int	x)
{
	if (list->width > ft_len_of_int(x))
		list->widthofline = list->width;
	else
		if (list->presicion < ft_len_of_int(x) && list->presicion > 0)
			list->widthofline = list->presicion;
		else
			list->widthofline = ft_len_of_int(x);
	if (list->presicion < ft_len_of_int(x) && list->presicion > 0)
		list->widthofcontent = list->presicion;
	else
		list->widthofcontent = ft_len_of_int(x);
}
