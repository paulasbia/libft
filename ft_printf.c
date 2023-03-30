/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:27:43 by paula             #+#    #+#             */
/*   Updated: 2023/03/30 11:27:13 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int replace(char st, va_list ap)
{
    int ret;

    ret = 0;
    if (st == '%')
    {
        ret = putchar('%');
    }
    if (st == 's')
    {
        ret = puts(va_arg(ap, char*));
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
    
    ret = ft_printf("ola %s %s\n", "ola", "ola");
    ret2 = printf("ola %s %s\n", "ola", "ola");
    printf("%d\n", ret);
    printf("%d\n", ret2);
}