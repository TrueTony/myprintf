# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
char	*adv_ft_itoa(long long n, int base, char c);

typedef union 	s_double
{
	double d;
	struct
	{
		unsigned long long m: 52;
		unsigned long long e: 11;
		unsigned long long s: 1;
	}			part;
}				t_double;

void	addit(unsigned long long *arr, int i, unsigned long long num)
{
	unsigned long long x;

	x = 10000000000;
	arr[i] += num % x;
	if (arr[i] + num % x > 999999999 || num / x > 0)
		addit(arr, i - 1, num / x);
}

void	mult(unsigned long long *arr, int i, int num, int end)
{
	unsigned long long x;
	unsigned long long res;

	if (i == end)
		return ;
	x = 10000000000;
	res = arr[i] * num;
	if (res > 999999999)
		addit(arr, i - 1, res / x);
	arr[i] = res % x;
	mult(arr, i + 1, num, end);
}

char	*full_str(char *str)
{
	int i;
	int	j;
	int len;
	char *res;

	i = 0;
	j = 0;
	len = 10 - ft_strlen(str);
	if (!(res = (char*)malloc(sizeof(char) * (11))))
		return (NULL);
	res[10] = '\0';
	while (len > 0)
	{
		res[i] = '0';
		i++;
		len--;
	}
	while (i < 10)
	{
		res[i] = str[j];
		i++;
		j++;
	}
	return (res);
}

int		main(void)
{
	double d;
	t_double d1;
	unsigned long long *arr;
	int i;
	int j;
	int countofel = 15;
	int pow;

	i = 0;
	pow = 52;
	d = 123456.1234567;
	d1.d = d;
	arr = (unsigned long long*)malloc(sizeof(unsigned long long) * countofel);
    while (i < countofel)
    {
        arr[i] = 0;
        i++;
    }
	addit(arr, countofel - 1, d1.part.m);
	while (pow)
	{
		mult(arr, 0, 5, countofel);
		pow--;
	}
	pow = 52;
	i = pow / 10;
	pow = pow % 10;
	addit(arr, 9, 100);
	pow = d1.part.e - 1023;
	while (pow)
	{
		mult(arr, 0, 2, countofel);
		pow--;
	}
	i = 0;
	int n = 98;
	int p = 6;
	char *tmp;
	while (arr[i] == 0 || n > 10)
	{
		i++;
		n -= 10;
	}
	tmp = full_str(adv_ft_itoa(arr[i], 10, 'a'));
	while (*tmp == '0')
	{
		tmp++;
		n--;
	}
	while (n--)
		ft_putchar(*tmp++);
	ft_putchar('.');
	while (p)
	{
		if (*tmp)
		{
			ft_putchar(*tmp++);
			p--;
		}
		else
		{
			i++;
			tmp = full_str(adv_ft_itoa(arr[i], 10, 'a'));
		}
	}
	return (0);
}
