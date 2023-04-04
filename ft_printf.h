/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:41:39 by paula             #+#    #+#             */
/*   Updated: 2023/04/04 14:29:06 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "libft.h"

void    ft_putuninbr(unsigned int n, int fd);
int     ft_printf(const char *, ...);
char    *ft_uitoa(unsigned long int n);
void    ft_hexanbr_fd(int n, int fd, int x);
void    ft_adressp(unsigned long int n, int fd, int x);



#endif