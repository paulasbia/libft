/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz < pde-souz@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:55:02 by pde-souz          #+#    #+#             */
/*   Updated: 2023/04/12 11:43:39 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == 0)
		return (0);
	if (start >= ft_strlen(s))
	{
		sub = malloc(1);
		*sub = 0;
		return (sub);
	}
	if (ft_strlen(s) - start >= len)
		sub = (char *)malloc(sizeof(char) * (len + 1));
	else
		sub = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (sub == 0)
		return (NULL);
	i = 0;
	while (s[start] && i < len && start < ft_strlen(s))
	{
		sub[i] = s[start++];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
