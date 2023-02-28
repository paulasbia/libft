run:
	gcc -g3 ft_*.c libft.h main.c -o result.out

clean:
	rm -f result.out

all: clean run
	./result.out