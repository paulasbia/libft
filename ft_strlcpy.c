/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:41:29 by paula             #+#    #+#             */
/*   Updated: 2023/03/02 13:01:22 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcpy(char *dest, const char *src, size_t size)
{
    size_t  i;
    size_t  srclen;

    srclen = ft_strlen(src);
    i = 0;
    while (src[i] != 0 && i < (size - 1))
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (srclen);    
}
