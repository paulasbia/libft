# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paula <paula@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 17:48:30 by paula             #+#    #+#              #
#    Updated: 2023/03/21 12:50:11 by paula            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE = libft.h
SRCS := $(wildcard ft_*.c)
SRCS := $(filter-out ft_lst*.c, $(SRCS))
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

%.o: $(SRCS)%.c $(INCLUDE)%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $(OBJS)/$@

$(NAME): $(OBJS)
	ar -crs $(NAME) $(OBJS)

test:
	gcc -ggdb $(FLAGS) $(SRCS) libft.h main.c unity_internals.h unity.c unity.h -lbsd -o result.out
   
run:
	./result.out

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all

valgrind: test
	valgrind --leak-check=full ./result.out

.PHONY: clean fclean all re