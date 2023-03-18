/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:39:18 by paula             #+#    #+#             */
/*   Updated: 2023/03/18 11:14:31 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t     cal_count(char const *s, char c)
{
    size_t  count;

    count = 1;
    while (*s != 0)
    {
        if (*s != c && (*(s + 1) == c || *(s + 1) == 0))
        {
            count++;
        }     
        s++;
    }
    return(count);
}

char    **ft_split(char const *s, char c)
{
    char    **result;

    result = (char **)malloc(sizeof(char *) * cal_count(s, c));
    return(result);
}
