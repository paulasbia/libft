# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paula <paula@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 17:48:30 by paula             #+#    #+#              #
#    Updated: 2023/03/21 11:25:34 by paula            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE = libft.h
SRC := $(wildcard ft_*.c)
SRC := $(filter-out ft_lst*.c, $(SRC))
OBJ = $(SRC:.c=*.o)

FLAGS = -Wall -Wextra -Werror

%.o: $(SRC)%.c
	gcc $(FLAGS) -c $< $(INCLUDE) -o $@

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

test:
	gcc -ggdb $(FLAGS) $(SRC) libft.h main.c unity_internals.h unity.c unity.h -lbsd -o result.out
   
run:
	./result.out

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all

valgrind: test
	valgrind --leak-check=full ./result.out

.PHONY: clean fclean all re