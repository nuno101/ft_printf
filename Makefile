# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuno <nlouro@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 23:47:18 by nuno              #+#    #+#              #
#    Updated: 2021/09/26 10:06:13 by nlouro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

C_FLAGS =  -c -Wall -Wextra -Werror

C_FILES = ft_printf.c

OBJ_FILES = $(C_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar -rcs $(NAME) $(OBJ_FILES)

$(OBJ_FILES): $(C_FILES)
	gcc $(C_FLAGS) $(C_FILES)

clean:
	rm -f $(OBJ_FILES) 

fclean: clean
	rm -f $(OBJ_FILES) 
	rm -f $(NAME)

re: fclean all

t:
	gcc -Wall -Wextra -Werror test/test_ft_printf.c -o test_ft_printf.out
	chmod +x test_ft_printf.out
	./test_ft_printf.out
