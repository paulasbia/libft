/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz < pde-souz@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:37:13 by pde-souz          #+#    #+#             */
/*   Updated: 2023/04/14 09:56:40 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordc(const char *str, char c)
{
	size_t	count;

	count = 1;
	while (*str != 0)
	{
		if (*str != c && (*(str + 1) == c || *(str + 1) == 0))
		{
			count++;
		}
		str++;
	}
	return (count);
}

static char	*ft_wordd(char const *str, int start, int end)
{
	char	*new;
	int		k;

	k = 0;
	new = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!new)
		return (NULL);
	while (start < end)
	{
		new[k] = str[start];
		start++;
		k++;
	}
	new[k] = '\0';
	return (new);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	i = 0;
	j = 0;
	index = -1;
	split = (char **)malloc(((ft_wordc(s, c))) * sizeof(char *));
	if (!split || !s)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j] = ft_wordd(s, index, i);
			index = -1;
			j++;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
