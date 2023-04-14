/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz < pde-souz@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:53:32 by pde-souz          #+#    #+#             */
/*   Updated: 2023/04/11 14:54:30 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	size_t	s1_len;
	int		i;
	int		j;

	i = 0;
	s1_len = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) != NULL)
	{
		i++;
	}
	j = s1_len;
	while (ft_strchr(set, s1[j - 1]) != NULL)
	{
		j--;
	}
	copy = ft_substr(s1, i, j - i);
	return (copy);
}
