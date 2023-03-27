/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paula <paula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:59:40 by paula             #+#    #+#             */
/*   Updated: 2023/03/27 11:44:36 by paula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (find[j] == 0)
		return ((char *)str);
	while (str[i] != 0)
	{
        j = 0;
        while (str[i + j] != 0 && str[i + j] == find[j] && (i + j) < n)
        {
            if (find[j + 1] == 0)
            {
                return ((char *)&str[i]);
            }
            j++;
        }
        i++;
	}
	return (NULL);    
}
