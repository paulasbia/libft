/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:48:19 by paula             #+#    #+#             */
/*   Updated: 2023/03/16 13:45:46 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *s)
{
    char    *ptr;
    size_t  len;

    len = ft_strlen(s) + 1;
    ptr = (char *)malloc(len);
    if (ptr == NULL)
    {
        return (0);
    }
    ft_memcpy(ptr, s, len);
    return (ptr);    
}
