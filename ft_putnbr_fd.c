/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz < pde-souz@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:35:58 by pde-souz          #+#    #+#             */
/*   Updated: 2023/04/12 15:57:42 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(int n, int fd)
{
	int	digit;

	digit = n % 10;
	if (n > 9 || n < -9)
	{
		ft_print(n / 10, fd);
	}
	if (digit < 0)
	{
		digit = digit * -1;
	}
	digit = digit + 48;
	ft_putchar_fd(digit, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
	}
	ft_print(n, fd);
}
