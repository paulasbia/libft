/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz < pde-souz@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:39:18 by pde-souz          #+#    #+#             */
/*   Updated: 2023/04/11 14:39:31 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	char	*ret;

	nstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	ret = nstr;
	if (nstr == 0)
	{
		return (NULL);
	}
	while (*s1 != 0)
	{
		*nstr = *s1;
		nstr++;
		s1++;
	}
	while (*s2 != 0)
	{
		*nstr = *s2;
		nstr++;
		s2++;
	}
	*nstr = 0;
	return (ret);
}
