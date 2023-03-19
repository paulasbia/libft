/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:39:18 by paula             #+#    #+#             */
/*   Updated: 2023/03/19 11:00:25 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t     cal_count(char const *s, char c)
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

static char    *strings(char const *str, int start, int len)
{
    char    *new;
    char    *r_new;
    int     k;

    new = (char *)malloc(sizeof(char) * (len + 1));
    if (new == 0)
    {
        return (NULL);
    }
    r_new = new;
    k = 0;
    while (k < len)
    {
        *new = str[k + start];
        k++;
        new++;
    }
    *new = 0;
    return(r_new);    
}

static void create_word(char const *s, char c, char **result, size_t i, size_t *start)
{
    size_t     len;

    len = 1;    
    while (s[*start + len] != c && s[*start + len] != 0)
        len++;
    result[i] = strings(s, *start, len);
    *start += len;
}

char    **ft_split(char const *s, char c)
{
    char    **result;
    size_t     start;
    size_t     i;

    result = (char **)malloc(sizeof(char *) * cal_count(s, c));
    if (result == 0)
        return (NULL);
    start = 0;
    i = 0;
    while (start < ft_strlen(s))
    {
        if (s[start] != c && s[start] != 0)
        {
            create_word(s, c, result, i, &start);
            i++;
        }
        else if (s[start] == c)
            start++;
    }
    result[i] = 0;
    return(result);
}
