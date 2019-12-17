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

unsigned long long	ft_maxmin(char *notcs, int sign)
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

int		lennum(long long n)
{
	int	i;

	i = 0;
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
	i++;
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

	res = (char*)malloc(sizeof(char) * 2);
	if (!res)
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char			*ft_itoa(int n)
{
	char	*res;
	size_t	len;

	len = 0;
	len = lennum(n);
	if (len == 0)
		return ("");
	if (n == -2147483648)
		return (minimum());
	res = (char*)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	if (n == 0)
		return (nole());
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

double ft_pow_float(int a, int b)
{
    int i;
    float res;

    i = a;
    res = a;
    if (b == 0)
        return (1.0);
	if (b == 1)
		return (a);
    if (b > 0)
    {
        b--;
        while (b--)
            res = res * i;
    }
    else
        res = 1 / ft_pow_float(a, b * -1);
    return (res);
}

void	subst(unsigned long long *arr, int i, unsigned long long num, int end)
{
	unsigned long long x;
	unsigned long long res;

	x = 10000000000;
	if (num / x > 0)
    {
		subst(arr, i - 1, num / x, end);
        num = num % x;
    }
	res = arr[i] - num;
	if (arr[i] < num)
	{
		if (i < end)
			subst(arr, i + 1, 1, end);
		arr[i] = x - res;
	}
	else
		arr[i] = res;
}

void	divis(unsigned long long *arr, int i, int num)
{
	unsigned long long res;
	unsigned long long cell;
	unsigned long long x;
	int end;

	x = 10000000000;
	end = i;
	res = 0;
	i = 0;
	while (arr[i] == 0 && i < end)
		i++;
	cell = arr[i];
	while (i <= end)
	{
		res = (cell / num);
		cell = ((arr[i] % num) * x) + arr[i + 1];
		arr[i] = res;
		i++;
	}
}
