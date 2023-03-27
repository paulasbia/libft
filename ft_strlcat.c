/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:36:03 by paula             #+#    #+#             */
/*   Updated: 2023/03/27 10:33:55 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t  i;
    size_t  j;

    if (size <= ft_strlen(dest))
    {
        return (size + ft_strlen(src));
    }
    i = ft_strlen(dest);
    j = 0;
    while (src[j] != 0 && (i + 1) < size)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = 0;
    return (i + ft_strlen(&src[j]));
}