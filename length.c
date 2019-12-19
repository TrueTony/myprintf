#include "printf.h"

void change_length_di(t_printf *list, long long x)
{
	if (list->length == "hh")
		x = (signed char)x;
	else if (list->length == "h")
		x = (short)x;
	else if (list->length == "l")
		x = (long)x;
	else if (list->length == "ll")
		x = (long long)x;
}

void change_length_u_x(t_printf *list, long long x)
{
	if (list->length == "hh")
		x = (unsigned char)x;
	else if (list->length == "h")
		x = (unsigned short)x;
	else if (list->length == "l")
		x = (unsigned long)x;
	else if (list->length == "ll")
		x = (unsigned long long)x;
}

void change_length_f_e_a_g(t_printf *list, double x)
{
	if (list->length == "l")
		x = (double)x;
	else if (list->length == "ll")
		x = (long double)x;
}