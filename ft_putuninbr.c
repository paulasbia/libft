/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuninbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:44:28 by paula             #+#    #+#             */
/*   Updated: 2023/03/31 09:01:57 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void    ft_uniprint(unsigned int n, int fd)
{
    unsigned int digit;

    digit = n % 10;
    if (n > 9)
    {
        ft_uniprint(n/10, fd);
    }
    digit = digit + 48;
    ft_putchar_fd(digit, fd);
}

void    ft_putuninbr(unsigned int n, int fd)
{
    ft_uniprint(n, fd);    
}