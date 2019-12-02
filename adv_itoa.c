#include "printf.h"

char	*minimum(void);
char	*nole(void);

size_t	lennum_base(int n, int base)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n >= base)
	{
		n /= base;
		i++;
	}
	return (i);
}

char			size_of_letter(char c)
{
	if (c >= 'a')
		return ('a');
	return ('A');
}

char			*adv_ft_itoa(int n, int base, char c)
{
	char	*res;
	size_t	len;
	char	cc;

	cc = size_of_letter(c);
	len = lennum_base(n, base);
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
		if (n % base > 9)
			res[len--] = (n % base) + (cc - 10);
		else
			res[len--] = (n % base) + '0';
		n /= base;
	}
	return (res);
}
