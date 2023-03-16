# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paula <paula@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 17:48:30 by paula             #+#    #+#              #
#    Updated: 2023/03/09 13:14:34 by paula            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

build:
	gcc -ggdb -Wall -Wextra ft_*.c libft.h main.c unity_internals.h unity.c unity.h -lbsd -o result.out
   

run:
	./result.out

clean:
	rm -f result.out

all: clean build run

valgrind: build
	valgrind --leak-check=full ./result.out