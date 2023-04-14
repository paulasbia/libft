/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz < pde-souz@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:42:59 by pde-souz          #+#    #+#             */
/*   Updated: 2023/04/11 14:43:08 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
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
