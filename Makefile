# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paula <paula@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 17:48:30 by paula             #+#    #+#              #
#    Updated: 2023/03/01 13:20:55 by paula            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

run:
	gcc -Wall -Werror -Wextra ft_*.c libft.h main.c -o result.out

clean:
	rm -f result.out

all: clean run
	./result.out