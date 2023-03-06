# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paula <paula@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 17:48:30 by paula             #+#    #+#              #
#    Updated: 2023/03/06 13:50:03 by paula            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

build:
	gcc -ggdb -Wall -Werror -Wextra ft_*.c libft.h main.c unity_internals.h unity.c unity.h -o result.out
   

run:
	./result.out

clean:
	rm -f result.out

all: clean build run
	