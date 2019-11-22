#include <stdlib.h>
#include <unistd.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar(2 + '0');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	while (n >= 10)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	ft_putchar(n + '0');
}

void	ft_putstr(char const *s)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return ;
	i = ft_strlen(s);
	write(1, s, i);
}

int		ft_prefics(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	return (i);
}

static	unsigned long long	ft_maxmin(char *notcs, int sign)
{
	unsigned long long	res;
	size_t				i;

	i = 0;
	res = 0;
	while (notcs[i] >= '0' && notcs[i] <= '9')
	{
		res = (res * 10) + (notcs[i] - '0');
		i++;
	}
	if (sign == -1)
	{
		if (res == 9223372036854775807)
			return (0);
		if (res > 9223372036854775807)
			return (0);
		return (res);
	}
	if (res == 9223372036854775807)
		return (-1);
	if (res > 9223372036854775807)
		return (-1);
	return (res);
}

int							ft_atoi(const char *str)
{
	size_t				i;
	int					sign;
	unsigned long long	res;
	char				*notcs;

	notcs = (char*)str;
	res = 0;
	sign = 1;
	i = ft_prefics(notcs);
	if (notcs[i] == '-' || notcs[i] == '+')
	{
		if (notcs[i] == '-')
			sign = -1;
		i++;
	}
	res = ft_maxmin(notcs + i, sign);
	return (((int)res) * sign);
}
