/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:53:59 by paula             #+#    #+#             */
/*   Updated: 2023/03/08 11:38:49 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *nstr;
    char    *ret;

    nstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    ret = nstr;
    if (nstr == 0)
    {
        return (NULL);
    }
    while (*s1 != 0)
    {
        *nstr = *s1;
        nstr++;
        s1++;
    }
    while (*s2 != 0)
    {
        *nstr = *s2;
        nstr++;
        s2++;
    }
    *nstr = 0;
    return (ret);    
}
