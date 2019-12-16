# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
char	*nole(void);

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
	//printf("arr[i]:%llu i:%d\n", arr[i], i);
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

int		findfirstel(unsigned long long *arr, int end)
{
	int i;

	i = 0;
	while (i < end)
	{
		if (arr[i] != 0)
			return (i);
		i++;
	}
	return (end);
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
	i = findfirstel(arr, end);
	cell = arr[i];
	while (i <= end)
	{
		res = (cell / num);
		//printf("cell:%llu / num:%d = res:%llu\n", cell, num, res);
		cell = ((arr[i] % num) * x) + arr[i + 1];
		arr[i] = res;
		i++;
	}
}

int		numlen(unsigned long long num)
{
	int	res;

	res = 1;
	while (num >= 10)
	{
		num /= 10;
		res++;
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

char			*adv_ft_itoa(long long n, int base, char c)
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
	printf("\nm:%llu e:%u s:%u\n\n", (unsigned long long)d1.part.m, d1.part.e, d1.part.s);
	arr = (unsigned long long*)malloc(sizeof(unsigned long long) * countofel);
    while (i < countofel)
    {
        arr[i] = 0;
        i++;
    }

	addit(arr, countofel - 1, d1.part.m);
	i = 0;
	while (i < countofel)
    {
		j = numlen(arr[i]);
		while (j < 10)
		{
			printf("0");
			j++;
		}
        printf("%llu", arr[i]);
        i++;
    }
	printf("\n");
	while (pow)
	{
		mult(arr, 0, 5, countofel);
		pow--;
	}
	pow = 52;
	i = pow / 10;
	pow = pow % 10;
	addit(arr, countofel - 1 - i, (int)ft_pow_float(10, pow));
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
		printf("%c", *tmp++);
	printf(".");
	while (p)
	{
		if (*tmp)
		{
			printf("%c", *tmp++);
			p--;
		}
		else
		{
			i++;
			tmp = full_str(adv_ft_itoa(arr[i], 10, 'a'));
		}
	}

	printf("\n");
	return (0);
}
