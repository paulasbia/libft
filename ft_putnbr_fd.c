/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:23:17 by paula             #+#    #+#             */
/*   Updated: 2023/03/17 13:28:00 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_print(int n, int fd)
{
    int digit;

    digit = n % 10;
    if (digit < 0)
    {
        digit = digit * -1;
    }
    if (n > 9 || n < -9)
    {
        ft_print(n/10, fd);
    }
    digit = digit + 48;
    ft_putchar_fd(digit, fd);
}

void    ft_putnbr_fd(int n, int fd)
{
    if (n < 0)
    {
        ft_putchar_fd('-', fd);
    }
    ft_print(n, fd);    
}