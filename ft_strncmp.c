/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:12:53 by paula             #+#    #+#             */
/*   Updated: 2023/03/27 10:44:04 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    if (n == 0)
        return(0);
    while (s1[i] == s2[i] && s1[i] != 0 && i < n - 1)
    {       
        i++;
    }
    return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
