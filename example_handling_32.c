# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef union s_float {
    float f;
    struct {
    unsigned int m: 23;
    unsigned int e: 8;
    unsigned int s: 1;
    }   part;
}       t_float;

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
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

double ft_pow_float(int a, int b)
{
    int i;
    float res;

    i = a;
    res = a;
    if (b == 0)
        return (1.0);
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

int main(void)
{
    t_float d1;
	float f = 236565.15435357625;

    d1.f = f;
    printf("sign = %d\n", d1.part.s);
    printf("exponent = %d\n", d1.part.e);
    printf("mantisa = %d\n", d1.part.m);
    //printf("sign = %d\n", d1.j_float.s);
    //printf("exponent = %d\n", adv_itoa(d1.j_float.e, 16));
    //printf("mantisa = %d\n", adv_itoa(d1.j_float.m, 16));
    char *two = adv_ft_itoa(d1.part.m, 2, 'c');
    int a = ft_strlen(two);
    while (a < 23)
    {
        printf("0");
        a++;
    }
    printf("%s %zu\n", two, ft_strlen(two));
    int e = d1.part.e - 127;
    printf("original exponent %d\n", e);
    float res;
    res = 0;
    res = 1 * ft_pow_float(2, e);
    e--;
    a = ft_strlen(two);
    while (a < 23)
    {
        e--;
        a++;
    }
    printf("exponent after shift %d\n", e);
    while (*two)
    {
        res +=  (*two - 48) * ft_pow_float(2, e);
        e--;
        two++;
    }
    printf("%f\n", res);
	printf("%f\n", f);
    return (0);
}