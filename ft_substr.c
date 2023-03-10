/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:04:42 by paula             #+#    #+#             */
/*   Updated: 2023/03/09 09:07:41 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *sub;
    size_t  s_len;
    
    if (s == 0)
    {
        return (0);
    }
    s_len = ft_strlen(s) + 1;
    if (start >= s_len)
	{
        return (NULL);
	}
    sub = malloc(sizeof(char) * (s_len - start));
    if (sub == 0)
    {
        return (NULL);
    }
    ft_memcpy(sub, &s[start], len);
    sub[len] = 0;
    return (sub);    
}