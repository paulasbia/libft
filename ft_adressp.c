/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adressp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:38:45 by paula             #+#    #+#             */
/*   Updated: 2023/04/04 14:15:11 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void    ft_adressp(unsigned long int n, int fd, int x)
{
    int digit;

    digit = n % 16;
    if (n >= 16)
    {
        ft_adressp(n/16, fd, x);
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
}
