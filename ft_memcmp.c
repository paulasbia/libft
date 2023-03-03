/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:16:18 by paula             #+#    #+#             */
/*   Updated: 2023/03/03 14:50:27 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    while (n > 0)
    {
        if (*((unsigned char *)s1) != *((unsigned char *)s2))
        {
            return (*((unsigned char *)s1) - *((unsigned char *)s2));
        }
        n--;
        s1++;
        s2++;
    }
    return (0);
}