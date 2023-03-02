/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:34:14 by paula             #+#    #+#             */
/*   Updated: 2023/03/02 11:00:42 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t  i;

    if ((dest == NULL) && (src == NULL))
    {
        return (NULL);
    }
    i = 0;
    if (dest > src)
    {
        while (n > 0)
        {
            ((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
            n--;
        }
    }
    else
    {
        while (n > 0)
        {
            ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
            i++;
        }
    }
    return (dest);
}