# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paula <paula@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 17:48:30 by paula             #+#    #+#              #
#    Updated: 2023/03/22 10:31:15 by paula            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =  ft_isalpha.c  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
		ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

%.o: %.c
	cc $(FLAGS) -c $< -o $@

all: $(NAME)

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

re: fclean all

valgrind: test
	valgrind --leak-check=full ./result.out

.PHONY: clean fclean all re