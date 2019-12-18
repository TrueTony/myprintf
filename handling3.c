# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

#include "printf.h"

size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
char	*adv_ft_itoa(long long n, int base, char c);
int		lennum(long long n);

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

int		handling_float(double d, int countofel, int pow, int p, t_printf *list)
{
	t_double 			d1;
	unsigned long long 	*arr;
	int 				i;
	char 				*tmp;
	int 				n;
	int 				iszero;

	iszero = 0;
	//printf("d:%f\n", d);
	n = 98;
	i = 0;
	if ((int)d == 0)
	{
		d += 1;
		iszero = 1;
	}
	//printf("d:%f\n", d);
	d1.d = d;
	//printf("m:%llu e:%llu\n", d1.part.m, d1.part.e);
	arr = (unsigned long long*)malloc(sizeof(unsigned long long) * countofel);
    while (i < countofel)
    {
        arr[i] = 0;
        i++;
    }
	//printf("\ntest\n");
	addit(arr, countofel - 1, d1.part.m);
	while (pow)
	{
		mult(arr, 0, 5, countofel);
		pow--;
	}
	addit(arr, 9, 100);
	pow = d1.part.e - 1023;
	//printf("pow:%d\n", pow);
	while (pow)
	{
		mult(arr, 0, 2, countofel);
		pow--;
	}
	/*
	int j;
	i = 0;
	while (i < countofel)
    {
		j = lennum(arr[i]);
		while (j < 10)
		{
			printf("0");
			j++;
		}
        printf("%I64d", arr[i]);
        i++;
    }
	printf("\n");
	*/
	i = 0;
	while (arr[i] == 0 && n > 10)
	{
		i++;
		n -= 10;
	}
	//printf("n:%d\n", n);
	tmp = full_str(adv_ft_itoa(arr[i], 10, 'a'));
	//printf("tmp:%s\n", tmp);
	while (*tmp == '0')
	{
		tmp++;
		n--;
	}
	if (iszero)
	{
		ft_putchar_cow('0', list);
		n--;
		tmp++;
	}
	//printf("%s\n", tmp);
	while (n)
		if (*tmp)
		{
			ft_putchar_cow(*tmp++, list);
			n--;
		}
		else
		{
			i++;
			tmp = full_str(adv_ft_itoa(arr[i], 10, 'a'));
		}
	if (p)
		ft_putchar_cow('.', list);
	while (p)
	{
		if (*tmp)
		{
			ft_putchar_cow(*tmp++, list);
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
