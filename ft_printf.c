/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:27:43 by paula             #+#    #+#             */
/*   Updated: 2023/04/04 14:46:42 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int replace(char st, va_list ap)
{
    int ret;
    char    *arg;
    int     arg_i;
    unsigned long int   arg_iu;

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
        arg = ft_itoa(arg_i);
        ret = ft_strlen(arg);
        free(arg);
    }
    if (st == 'u')
    {
        arg_i = va_arg(ap, int);
        ft_putuninbr(arg_i, 1);
        arg = ft_uitoa(arg_i);
        ret = ft_strlen(arg);
        free(arg);
    }
    if (st == 'x')
    {
        arg_i = va_arg(ap, int);
        ft_hexanbr_fd(arg_i, 1, 1);
        arg = ft_uitoa(arg_i);
        ret = ft_strlen(arg);
        free(arg);
    }
    if (st == 'X')
    {
        arg_i = va_arg(ap, int);
        ft_hexanbr_fd(arg_i, 1, 2);
        arg = ft_uitoa(arg_i);
        ret = ft_strlen(arg);
        free(arg);
    }
    if (st == 'p')
    {
        arg_iu = va_arg(ap, unsigned long int);
        ft_putstr_fd("0x", 1);
        ft_adressp(arg_iu, 1, 1);
        arg = ft_uitoa(arg_iu);
        ret = ft_strlen(arg) + 2;
        free(arg);
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
    char    s[] = "ola";
    int     d = 15;
    
    ret = ft_printf("ola %s %s %c %d %% %u %x %X %p\n", s, s, 'a', d, 2147483648, d, d, &s);
    ret2 = printf("ola %s %s %c %d %% %u %x %X %p\n", s, s, 'a', d, (unsigned int)2147483648, d, d, &s);
    printf("%d\n", ret);
    printf("%d\n", ret2);
}