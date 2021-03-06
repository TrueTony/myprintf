# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 15:45:02 by ksenaida          #+#    #+#              #
#    Updated: 2019/12/18 18:50:12 by ksenaida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

SRC = adv_itoa.c find_args_of_list.c ft_printf.c struckts.c type_c.c type_d_and_i.c \
		type_f_and_F.c type_str.c type_u.c type_x_and_X.c \
		handling3.c ./libft/*.c
OBJ = $(SRC:.c=.o)
HDR = printf.h
LIBFT = libft/
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		gcc $(FLAGS) -c -I$(HDR) -I ./libft $(SRC)
		ar rc $(NAME) *.o
		ranlib $(NAME)


clean:
	rm -rf $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf *.o


re: fclean all

.PHONY: all clean fclean re
