/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:37:37 by paula             #+#    #+#             */
/*   Updated: 2023/04/04 11:24:04 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void    ft_print_hexa(int n, int fd, int x)
{
    int digit;

    digit = n % 16;
    if (digit < 0)
    {
        digit = digit * -1;
    }
    if (n >= 16 || n <= -16)
    {
        ft_print_hexa(n/16, fd, x);
    }
    if (digit <= 9)
    {
        digit = digit + 48;
        ft_putchar_fd(digit, fd);
    }
    else if (digit > 9 && x == 1)
    {
        digit = digit + 87;
        ft_putchar_fd(digit, fd);
    }
    else if (digit > 9 && x == 2)
    {
        digit = digit + 55;
        ft_putchar_fd(digit, fd);
    }
    
}

void    ft_hexanbr_fd(int n, int fd, int x)
{
    if (n < 0)
    {
        ft_putchar_fd('-', fd);
    }
    ft_print_hexa(n, fd, x);    
}