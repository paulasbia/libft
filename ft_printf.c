/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:27:43 by paula             #+#    #+#             */
/*   Updated: 2023/03/31 08:35:27 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int replace(char st, va_list ap)
{
    int ret;
    char    *arg;
    int     arg_i;

    ret = 0;
    if (st == '%')
    {
        ft_putchar_fd(st, 1);
        ret++;
    }
    if (st == 'c')
    {
        ft_putchar_fd(va_arg(ap, int), 1);
        ret++;
    }
    if (st == 's')
    {
        arg = va_arg(ap, char*);
        ft_putstr_fd(arg, 1);
        ret = ft_strlen(arg);
    }
    if (st == 'd' || st == 'i')
    {
        arg_i = va_arg(ap, int);
        ft_putnbr_fd(arg_i, 1);
        ret = ft_strlen(ft_itoa(arg_i));
    }
    
    return(ret);
}

int ft_printf(const char *st, ...)
{
    int     ret;
    int     i;
    va_list ap;

    ret = 0;
    i = 0;
    va_start(ap, st);
    while (st[i] != 0)
    {
        if (st[i] == '%')
        {
            ret = ret + replace(st[++i], ap);
        }
        else
            ret = ret + write(1, &st[i], 1);
        i++;
    }
    va_end(ap);
    return(ret);
}

int main(void)
{
    int ret;
    int ret2;
    
    ret = ft_printf("ola %s %s %c %d %%\n", "ola", "ola", 'a', -42);
    ret2 = printf("ola %s %s %c %d %%\n", "ola", "ola", 'a', -42);
    printf("%d\n", ret);
    printf("%d\n", ret2);
}