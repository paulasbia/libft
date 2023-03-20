/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:37:10 by paula             #+#    #+#             */
/*   Updated: 2023/03/20 12:44:00 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char            *new;
    unsigned int    i;

    new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
    if (new == 0)
    {
        return(NULL);
    }
    i = 0;
    while (s[i] != 0)
    {
        new[i] = f(i, s[i]);
        i++;
    }
    new[i] = 0;
    return(new);
}