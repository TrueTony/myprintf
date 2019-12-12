# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

void    in_arr2(int a, int b, int *arr, int i, int buf)
{
    int res;
    int tmp;
    int tmp_i;

    tmp_i = i - 1;
    res = a % 10000 + b % 10000;
    buf = res / 10000;
    tmp = arr[i] + res;
    if (tmp > 9999)
    {
        in_arr2(arr[i], res / 10000, arr, tmp_i, buf);
    }
    if (i > 0 && (arr[tmp_i] + buf) > 9999)
    {
        in_arr2(arr[i], buf, arr, tmp_i, buf);
    }
    arr[i] = tmp;
    if (tmp > 0)
        in_arr2(a / 10000, b / 10000, arr, tmp_i, buf);

}

int main(void)
{
    int *arr;
    int i;

    i = 0;
    arr = (int*)malloc(sizeof(int) * 4);
    while (i < 4)
    {
        arr[i] = 0;
        i++;
    }
    in_arr2(44565871, 4634564, arr, 3, 0);
    i = 0;
    while (i < 4)
    {
        printf("%d", arr[i]);
        i++;
    }
    return (0);
}