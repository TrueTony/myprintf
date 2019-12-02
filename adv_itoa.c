#include "printf.h"

int		lennum(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*minimum(void)
{
	int					i;
	int					n;
	char				*res;

	i = 10;
	n = -2147483648;
	res = (char*)malloc(sizeof(char) * 12);
	if (!res)
		return (NULL);
	res[0] = '-';
	while (i > 0)
	{
		res[i] = (n % 10) * -1 + '0';
		n /= 10;
		i--;
	}
	res[11] = '\0';
	return (res);
}

char	*nole(void)
{
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char			*adv_ft_itoa(int n)
{
	char	*res;
	size_t	len;

	len = lennum(n);
	if (len == 0)
		return ("");
	if (n == 0)
		return (nole());
	if (n == -2147483648)
		return (minimum());
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len--] = '\0';
	if (n < 0)
		res[0] = '-';
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		res[len--] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
