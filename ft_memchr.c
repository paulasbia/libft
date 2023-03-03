/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:46:30 by paula             #+#    #+#             */
/*   Updated: 2023/03/03 14:12:24 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    size_t  i;

    i = 0;
    while (i < n)
    {
        if (((unsigned char *)s)[i] == ((unsigned char)c))
        {
            return ((void *)(s + i));
        }
        i++;
    }
    return (NULL);
}
