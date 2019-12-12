# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

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

void    in_arr(unsigned long long a, unsigned long long b, unsigned long long *arr, int i, unsigned long long buf)
{
    unsigned long long res;
    unsigned long long tmp;
    int tmp_i;

    tmp_i = i - 1;
    res = a % 10000 + b % 10000;
    printf("%llu %llu %llu\n", a % 10000, b % 10000, a % 10000 + b % 10000);
    buf = res / 10000;
    printf("%llu\n", res / 10000);
    tmp = arr[i] + res;
    if (tmp > 9999)
    {
        in_arr(arr[tmp_i], res / 10000, arr, tmp_i, buf);
    }
    arr[i] = tmp % 10000;
    if (a / 10000 > 0 || b / 10000 > 0)
        in_arr(a / 10000, b / 10000, arr, tmp_i, buf);

}

int main(void)
{
    unsigned long long *arr;
    int i;

    i = 0;
    arr = (unsigned long long*)malloc(sizeof(unsigned long long) * 5);
    while (i < 5)
    {
        arr[i] = 0;
        i++;
    }
    double a = 44565871.34;
    double b = 4634564.12;
    int    stepen = 2;
    unsigned long long d = a*ft_pow_float(10, stepen);
    unsigned long long e = b*ft_pow_float(10, stepen);
    printf("%llu\n", d);
    printf("%llu\n", e);
    in_arr(d, e, arr, 4, 0);
    i = 0;

    while (i < 5)
    {
		if (i == 4)
			printf("%llu.%llu", arr[i] / (int)ft_pow_float(10, stepen), arr[i] % (int)ft_pow_float(10, stepen));
		else
        	printf("%llu", arr[i]);
        i++;
    }
    return (0);
}