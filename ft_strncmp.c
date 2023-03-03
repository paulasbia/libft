/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:12:53 by paula             #+#    #+#             */
/*   Updated: 2023/03/03 10:25:08 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while (s1[i] != 0 && i < n)
    {
        if (s1[i] != s2[i])
            return (((const unsigned char *)s1)[i] - ((const unsigned char *)s2)[i]);
        i++;
    }
    return (0);
}
