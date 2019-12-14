# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

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
	printf("arr[i]:%llu i:%d\n", arr[i], i);
	if (arr[i] + num % x > 999999999 || num / x > 0)
		addit(arr, i - 1, num / x);
}

void	mult(unsigned long long *arr, int i, int num)
{
	unsigned long long x;
	unsigned long long res;

	if (i < 0)
		return ;
	x = 10000000000;
	res = arr[i] * num;
	if (res > 999999999)
		addit(arr, i - 1, res / x);
	arr[i] = res % x;
	mult(arr, i - 1, num);

}

int		main(void)
{
	double d;
	t_double d1;
	unsigned long long *arr;
	int i;
	int countofel = 12;
	int pow;

	i = 0;
	pow = 5;
	d = 123456789;
	d1.d = d;
	printf("\nm:%llu e:%llu s:%llu\n\n", d1.part.m, d1.part.e, d1.part.s);
	arr = (unsigned long long*)malloc(sizeof(unsigned long long) * countofel);
    while (i < countofel)
    {
        arr[i] = 0;
        i++;
    }
	addit(arr, countofel - 1, d1.part.m);
	while (pow)
	{
		printf("pow=%d\n", pow);
		mult(arr, countofel - 1, 10);
		pow--;
	}
	i = 0;
	while (i < countofel)
    {
        printf("%llu", arr[i]);
        i++;
    }
	printf("\n");
	return (0);
}