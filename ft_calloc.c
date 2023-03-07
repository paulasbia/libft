/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:42:05 by paula             #+#    #+#             */
/*   Updated: 2023/03/07 15:52:03 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t nmemb, size_t size)
{
    void    *ptr;
    size_t  totalsize;

    totalsize = (nmemb * size);
    if (nmemb == 0 || size == 0)
    {
        return (NULL);
    }
    ptr = malloc(totalsize);
    if(ptr == NULL)
    {
        return (NULL);
    }
    ft_bzero(ptr, totalsize);
    return (ptr);
}
