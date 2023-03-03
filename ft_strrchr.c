/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:31:18 by paula             #+#    #+#             */
/*   Updated: 2023/03/03 10:00:28 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    int len;

    len = ft_strlen(s);
    while (len >= 0)
    {
        if (s[len] == ((char)c))
        {
            return ((char *)&s[len]);
        }
        len--;
    }
    return (NULL);
}