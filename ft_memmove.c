/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:34:14 by paula             #+#    #+#             */
/*   Updated: 2023/03/06 16:16:03 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    if ((dest == NULL) || (src == NULL))
    {
        return (NULL);
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