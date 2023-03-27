/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:04:42 by paula             #+#    #+#             */
/*   Updated: 2023/03/27 11:10:28 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *sub;
    size_t  s_len;
    size_t     i;
    
    if (s == 0)
    {
        return (0);
    }   
    s_len = ft_strlen(s) + 1;
    if (start >= s_len)
	{
        sub = malloc(1);
        *sub = 0;
        return(sub);
	}
    if (s_len - start >= len)
        sub = (char *)malloc(sizeof(char) * (len + 1));
    else
        sub = (char *)malloc(sizeof(char) * (s_len - start));
    if (sub == 0)
    {
        return (NULL);
    }
    i = 0;
    while (s[start] && i < len && start < s_len)
    {
        sub[i] = s[start];
        i++;
        start++;
    }
    sub[i] = 0;
    return (sub);    
}