#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

# include <stdio.h>

void		ft_printf(char *format, ...);

/*
d, i
u
f, F
e, E
g, G
x, X
o
s
c
p
a, A
n
hh
h
l
ll
L
z
j
t
*/
// You have to manage the following conversions: diouxX with the following flags: hh, h, l and ll.
// You have to manage the following conversion: f with the following flags: l and L.
// You must manage %%
// You must manage the flags #0-+ and space
// You must manage the minimum field-width
// You must manage the precision

#endif
