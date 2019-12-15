# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef union 	s_double
{
	double d;
	struct
	{
		unsigned long long m: 53;
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

void	subst(unsigned long long *arr, int i, unsigned long long num)
{
	unsigned long long x;
	unsigned long long res;

	x = 10000000000;
	if (num / x > 0)
    {
		subst(arr, i - 1, num / x);
        num = num % x;
    }
	res = arr[i] - num;
	if (arr[i] < num)
	{
		subst(arr, i + 1, 1);
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

int		main(void)
{
	//double d;
	//t_double d1;
	unsigned long long *arr;
	int i;
	int j;
	int countofel = 5;
	int pow;

	i = 0;
	pow = 1;
	//d = 123456789;
	//d1.d = d;
	//printf("\nm:%llu e:%u s:%u\n\n", (unsigned long long)d1.part.m, d1.part.e, d1.part.s);
	arr = (unsigned long long*)malloc(sizeof(unsigned long long) * countofel);
    while (i < countofel)
    {
        arr[i] = 0;
        i++;
    }
	addit(arr, countofel - 1, 10000000000);
	i = 0;
	while (i < countofel)
    {
        printf("%llu", arr[i]);
        i++;
    }
	printf("\n");
	while (pow)
	{
		//printf("pow=%d\n", pow);
		mult(arr, countofel - 1, 2);
		pow--;
	}
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
	return (0);
}