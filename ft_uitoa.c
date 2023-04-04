/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:27:34 by paula             #+#    #+#             */
/*   Updated: 2023/04/04 14:28:56 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int    ulen(unsigned int n)
{
    unsigned int len;

    len = 1;
    while (n > 9)
    {
        len++;
        n = n / 10;
    }
    return(len);    
}

static void    ft_uprint(char *result, unsigned int n, unsigned int n_len)
{
    unsigned int    digit;

    digit = n % 10;
    if (n > 9)
    {
        ft_uprint(result, n/10, n_len - 1);
    }
    digit = digit + 48;
    result[n_len] = digit;
}

char    *ft_uitoa(unsigned long int n)
{
    char            *result;
    unsigned int     n_len;

    n_len = ulen(n); 

    result = (char *)malloc(sizeof(char) * n_len + 1);
    if (result == 0)
        return(NULL);
    result[n_len] = 0;
    n_len--;
    ft_uprint(result, n, n_len);
    return(result);
}