/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:34:14 by paula             #+#    #+#             */
/*   Updated: 2023/03/27 12:26:21 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    if (((unsigned char *)dest) == ((unsigned char *)src))
    {
        return (dest);
    }
    if (dest > src)
    {
        while (n > 0)
        {
            ((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
            n--;
        }
    }
    else
    {
        ft_memcpy(dest, src, n);
    }
    return (dest);
}